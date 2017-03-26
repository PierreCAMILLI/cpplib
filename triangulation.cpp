#include "include/triangulation.hpp"

void Triangulation::ImportFile(const std::string& file){
	std::string line;
    std::ifstream myfile (file.c_str());

    if(myfile.is_open()){
    	Clear();

    	// On alloue le nombre de vertices présents
    	unsigned int verSize;
    	myfile >> verSize;
    	vertices.reserve(verSize);

    	for(unsigned int i = 0; i < verSize; ++i){
    		getline(myfile, line);

    		// On lit les coordonnées du point
    		double x, y;
    		myfile >> x >> y;
    		AddVertice(Vector2_t<double>(x, y));
    	} 
    }
}

Triangulation& Triangulation::AddVertice(const Vector2_t<double>& vertice){
	vertices.push_back(vertice);
	
	if(vertices.size() == 3){
		
		VerticeIndex a = 0, b = 1, c = 2;
		SortVertices(a, b, c);

		faces.push_back(Face(a, b, c, 1, 2, 3));
		faces.push_back(Face(a, VERTICE_INDEX_INFINITY, b, 3, 2, 0));
		faces.push_back(Face(b, VERTICE_INDEX_INFINITY, c, 1, 3, 0));
		faces.push_back(Face(c, VERTICE_INDEX_INFINITY, a, 2, 1, 0));
	
	}else if(vertices.size() > 3){
		// On regarde si le vertex est inclu dans un triangle
		FaceIndex f;
		if(IsInside(vertice, f)){
			InsertLastVerticeInFace(f);
		}else{
			// Le vertex n'est pas dans la triangulation
			// On parcourt l'enveloppe convexe de la triangulation
			// On vérifie si on peut linker le vertex avec les côtés de l'enveloppe convexe
			InsertLastVerticeOutsideTriangulation();
		}
	}

	return (*this);
}

void Triangulation::Clear(){
	vertices.clear();
	faces.clear();
}

Mesh Triangulation::ToMesh() const{
	Mesh m;

	// Insertion des vertex
	m.GetVertices().reserve(vertices.size());
	for(VerticeIndex i = 0; i < vertices.size(); ++i){
		m.Vertice(vertices[i]);
	}

	// Insertion des faces
	m.GetVerticesIndex().reserve(vertices.size() * 3);
	for(FaceIndex i = 0; i < faces.size(); ++i){
		Face face = faces[i];
		if(!face.HasInfiniteVertice())	m.Triangle(face[0], face[1], face[2]);
	}

	return m;
}

bool Triangulation::IsUpside(const Vector2_t<double>& _o, const Vector2_t<double>& _a, const Vector2_t<double>& _b){
	Vector2_t<double>	AB = _b - _a,
						AO = _o - _a;
	return (AB.x * AO.y) > (AB.y * AO.x);
}

void Triangulation::SortVertices(VerticeIndex& _a, VerticeIndex& _b, VerticeIndex& _c){
	Vector2_t<double>	a = vertices[_a],
						b = vertices[_b],
						c = vertices[_c];
	const bool areInGoodOrder = IsUpside(c, a, b);
	if(!areInGoodOrder){
		VerticeIndex temp = _a;
		_a = _b;
		_b = temp;
	}
}

bool Triangulation::IsInside(const Vector2_t<double>& vertice, FaceIndex& face){
	for(FaceIndex i = 0; i < faces.size(); ++i){
		if(IsInsideFace(vertice, i)){
			face = i;
			return true;
		}
	}
	return false;
}

bool Triangulation::IsInsideFace(const Vector2_t<double>& vertice, const FaceIndex& _face){
	Face face = faces[_face];
	if(face.HasInfiniteVertice())	return false;
	
	Vector2_t<double>	a = vertices[face[0]],
						b = vertices[face[1]],
						c = vertices[face[2]];
	return (		IsUpside(vertice, a, b)
				&&	IsUpside(vertice, b, c)
				&&	IsUpside(vertice, c, a));
}

void Triangulation::InsertVerticeInFace(const VerticeIndex& vindex, const FaceIndex& findex){
	Face face = faces[findex];
	
	// Index des futures faces créées
	FaceIndex 	secondFace = faces.size(),
				thirdFace = faces.size() + 1;
	
	// On remplace la face courante par une des faces que l'on souhaite ajouter
	VerticeIndex verticeReplaced = face[0];
	faces[findex][0] = vindex;

	// On créé les nouvelles faces
	faces.push_back(Face(	vindex, verticeReplaced, face[1],
							thirdFace, face(0), findex));
	faces.push_back(Face(	vindex, face[2], verticeReplaced,
							findex, face(2), secondFace));

	// On met à jour les faces adjacentes de la face courante
	faces[face(0)].SetFaceIndexTo(findex, secondFace);
	faces[face(2)].SetFaceIndexTo(findex, thirdFace);

	faces[findex](0) = secondFace;
	faces[findex](2) = thirdFace;
}

void Triangulation::InsertLastVerticeOutsideTriangulation(){
	Vector2_t<double> lastVertice = vertices[vertices.size() - 1];
	FacesCirculator
		fc = GetFacesCirculator(VERTICE_INDEX_INFINITY),
		fc_end = fc;
	do{
		// TODO
		Face face = fc.GetFace();
		VerticeIndex va, vb;
				if(face.vertices.x == VERTICE_INDEX_INFINITY)	{	va = face.vertices.y;	vb = face.vertices.z;	}
		else	if(face.vertices.y == VERTICE_INDEX_INFINITY)	{	va = face.vertices.z;	vb = face.vertices.x;	}
		else													{	va = face.vertices.x;	vb = face.vertices.y;	}
		if(IsUpside(lastVertice, va, vb)){
			InsertLastVerticeInFace(*fc);
		}
	}while(fc != fc_end);
}