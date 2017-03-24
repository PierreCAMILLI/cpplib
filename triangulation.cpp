#include "include/triangulation.hpp"

void Triangulation::ImportFile(const std::string& file){

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
		FaceIndex f = IsInside(vertice);
		if(f >= 0){
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

Mesh Triangulation::ToMesh() const{
	Mesh m;

	// Insertion des vertex
	for(VerticeIndex i = 0; i < vertices.size(); ++i){
		m.Vertice(vertices[i]);
	}

	// Insertion des faces
	for(FaceIndex i = 0; i < faces.size(); ++i){
		Face face = faces[i];
		m.Triangle(face[0], face[1], face[2]);
	}

	return m;
}

bool Triangulation::IsUpside(const Vector2_t<double>& _o, const Vector2_t<double>& _a, const Vector2_t<double>& _b){
	Vector2_t<double>	AB = _b - _a,
						AO = _o - _a;
	return (AB.x * AO.y) > (AB.y * AO.x);
}

void Triangulation::SortVertices(VerticeIndex& _a, VerticeIndex& _b, VerticeIndex& _c){
	// TODO
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

FaceIndex Triangulation::IsInside(const Vector2_t<double>& vertice){
	for(FaceIndex i = 0; i < faces.size(); ++i){
		if(IsInsideFace(vertice, i)){
			return i;
		}
	}
	return -1;
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

void Triangulation::InsertLastVerticeInFace(const FaceIndex& index){
	VerticeIndex lastVerticeIndex = vertices.size() - 1;
	Face face = faces[index];
	FaceIndex 	secondFace = faces.size(),
				thirdFace = faces.size() + 1;
	
	// On remplace la face courante par une des faces que l'on souhaite ajouter
	VerticeIndex verticeReplaced = face[0];
	faces[index][0] = lastVerticeIndex;

	// On créé les nouvelles faces
	faces.push_back(Face(	lastVerticeIndex, verticeReplaced, face[1],
							thirdFace, face(0), index));
	faces.push_back(Face(	lastVerticeIndex, face[2], verticeReplaced,
							index, face(2), secondFace));

	// On met à jour les faces adjacentes de la face courante
	faces[face(0)].SetFaceIndexTo(index, secondFace);
	faces[face(2)].SetFaceIndexTo(index, thirdFace);

	faces[index](0) = secondFace;
	faces[index](2) = thirdFace;
}

void Triangulation::InsertLastVerticeOutsideTriangulation(){
	// TODO
}