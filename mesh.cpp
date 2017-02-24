#include "include/mesh.hpp"

void Mesh::release()
{
	MeshVertices vertices;
	MeshTextures textures;
	MeshNormals normals;

	MeshVerticesIndex vertices_index;
	MeshTexturesIndex textures_index;
	MeshNormalsIndex normals_index;
}

Mesh& Mesh::operator+=(const Vector3_t<double> & t){
	for(unsigned int i = 0; i < vertices.size(); i++){
		vertices[i] = vertices[i] + t;
	}
	return (*this);
}

Mesh& Mesh::operator*=(const double & s){
	for(unsigned int i = 0; i < vertices.size(); i++){
		vertices[i] = vertices[i] * s;
	}
	return (*this);
}

Mesh& Mesh::operator*=(const Vector3_t<double> & s){
	for(unsigned int i = 0; i < vertices.size(); i++){
		vertices[i] = vertices[i] * s;
	}
	return (*this);
}

Index Mesh::vertice(const Vector3_t<double> & _v){
	vertices.push_back(_v);
	return vertices.size() - 1;
}

Index Mesh::vertice(const double& x, const double& y, const double& z)
{
	vertice(Vector3_t<double>(x,y,z));
	return vertices.size() - 1;
}

Mesh& Mesh::texture(const Vector2_t<double> & _t){
	textures.push_back(_t);
	return (*this);
}

Mesh& Mesh::texture(const double& x, const double& y)
{
	texture(Vector2_t<double>(x,y));
	return (*this);
}

Mesh& Mesh::normal(const Vector3_t<double> & _n){
	normals.push_back(_n);
	return (*this);
}

Mesh& Mesh::normal(const double& x, const double& y, const double& z)
{
	normal(Vector3_t<double>(x,y,z));
	return (*this);
}

Mesh& Mesh::vertice_index(const Index & _vi){
	vertices_index.push_back(_vi);
	return (*this);
}

Mesh& Mesh::texture_index(const Index & _ti){
	textures_index.push_back(_ti);
	return (*this);
}

Mesh& Mesh::normal_index(const Index & _ni){
	normals_index.push_back(_ni);
	return (*this);
}

Mesh& Mesh::triangle(const Vector3_t<double> & a, const Vector3_t<double> & b, const Vector3_t<double> & c){
	unsigned int v_size = vertices.size();

	vertice(a);
	vertice(b);
	vertice(c);

	vertice_index(v_size);
	vertice_index(v_size+1);
	vertice_index(v_size+2);

	return (*this);
}

Mesh& Mesh::triangle(const Index & a, const Index & b, const Index & c){
	vertice_index(a);
	vertice_index(b);
	vertice_index(c);

	return (*this);
}

Mesh& Mesh::triangle_last(const int & a, const int & b, const int & c){
	vertice_index(vertices.size() + a);
	vertice_index(vertices.size() + b);
	vertice_index(vertices.size() + c);

	return (*this);
}

bool Mesh::importOBJ(const std::string & filename)
{
	FILE* file = fopen( filename.c_str(), "r" );

	if ( file == NULL ) {
		printf( "Impossible to open the file !\n" );
		return false;
	}

	clear();

	while( true ){

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break;	// EOF = End Of File. Quit the loop
		if( strcmp( lineHeader, "v" ) == 0 ){
			Vector3 vertex;
			fscanf(file, "%lf %lf %lf", &vertex.x, &vertex.y, &vertex.z);
			vertice(vertex);
		}else if(strcmp( lineHeader, "vt" ) == 0 ){
			Vector2 uv;
			fscanf(file, "%lf %lf", &uv.x, &uv.y);
			texture(uv);
		}else if(strcmp( lineHeader, "vn" ) == 0 ){
			Vector3 n;
			fscanf(file, "%lf %lf %lf", &n.x, &n.y, &n.z);
			normal(n);
		}else if ( strcmp( lineHeader, "f" ) == 0 ){
		    std::string vertex1, vertex2, vertex3;
		    unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
		    int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
		    	&vertexIndex[0], &uvIndex[0], &normalIndex[0],
		    	&vertexIndex[1], &uvIndex[1], &normalIndex[1],
		    	&vertexIndex[2], &uvIndex[2], &normalIndex[2] );
		    if (matches != 9){
		        printf("File can't be read by our simple parser : ( Try exporting with other options )\n");
		        return false;
		    }
		    vertice_index(vertexIndex[0]);
		    vertice_index(vertexIndex[1]);
		    vertice_index(vertexIndex[2]);
		    texture_index(uvIndex[0]);
		    texture_index(uvIndex[1]);
		    texture_index(uvIndex[2]);
		    normal_index(normalIndex[0]);
		    normal_index(normalIndex[1]);
		    normal_index(normalIndex[2]);
		}
	}

	return true;
}

bool Mesh::exportOBJ(const std::string & filename, const double scale)
{
	std::ofstream ofs( filename );

	if ( !ofs.good() )
		return  false;

	ofs << "#OBJ file\n";

	for(unsigned int i = 0; i < vertices.size(); i++){
		Vector3 const & vertex = vertices[i];
		ofs << "v " << (int)(vertex.x / scale) * scale << ' '
					<< (int)(vertex.y / scale) * scale << ' '
					<< (int)(vertex.z / scale) * scale << '\n';
	}

	for(unsigned int i = 0; i < textures.size(); i++){
		Vector2 const & texture = textures[i];
		ofs << "vt " 	<< (int)(texture.x / scale) * scale << ' '
						<< (int)(texture.y / scale) * scale << '\n';
	}

	for(unsigned int i = 0; i < normals.size(); i++){
		Vector3 const & normal = normals[i];
		ofs << "vn " 	<< (int)(normal.x / scale) * scale << ' '
						<< (int)(normal.y / scale) * scale << ' '
						<< (int)(normal.z / scale) * scale << '\n';
	}

	bool putNormals = normals_index.size() != 0;
	bool putTextures  = textures_index.size() != 0;
	for(unsigned int i = 0; i < vertices_index.size(); i+=3){
		
		ofs << "f ";

		for(unsigned int j = 0; j < 3; j++){
			ofs << vertices_index[i + j] + 1;

			if(putTextures)
				ofs << '/' << textures_index[i + j] + 1;
			else if(putNormals)
				ofs << '/';

			if(putNormals)
				ofs << '/' << normals_index[i + j] + 1;

			ofs << ' ';
		}

		ofs << '\n';
	}

	return true;
}

Mesh& Mesh::merge(const Mesh& _m)
{
	unsigned int 	v_size = vertices.size(),
					t_size = textures.size(),
					n_size = normals.size();
	for(MeshVerticesIndex::const_iterator it = _m.vertices_index.begin(); it != _m.vertices_index.end(); it++){
		vertices_index.push_back(*it + v_size);
	}
	for(MeshTexturesIndex::const_iterator it = _m.textures_index.begin(); it != _m.textures_index.end(); it++){
		textures_index.push_back(*it + t_size);
	}
	for(MeshNormalsIndex::const_iterator it = _m.normals_index.begin(); it != _m.normals_index.end(); it++){
		normals_index.push_back(*it + n_size);
	}

	vertices.insert(vertices.end(),_m.vertices.begin(),_m.vertices.end());
	textures.insert(textures.end(),_m.textures.begin(),_m.textures.end());
	normals.insert(normals.end(),_m.normals.begin(),_m.normals.end());

	return *this;
}


void Mesh::bounds(Point_t<double>& pmin, Point_t<double>& pmax)
{
	pmin = Point(vertices[0]);
	pmax = pmin;
	for(MeshVertices::const_iterator it = vertices.begin(); it != vertices.end(); it++){
		Point temp = Point(*it);
		pmin(std::min(pmin.x,temp.x),std::min(pmin.y,temp.y),std::min(pmin.z,temp.z));
		pmax(std::max(pmin.x,temp.x),std::max(pmin.y,temp.y),std::max(pmin.z,temp.z));
	}
}

void Mesh::resize(const double& scale){
	for(unsigned int i = 0; i < vertices.size(); i++)
		vertices[i] = vertices[i] * scale;

	for(unsigned int i = 0; i < textures.size(); i++)
		textures[i] = textures[i] * scale;

	for(unsigned int i = 0; i < normals.size(); i++)
		normals[i] = normals[i] * scale;
}

void Mesh::clear()
{
	vertices.clear();
	textures.clear();
	normals.clear();
	vertices_index.clear();
	textures_index.clear();
	normals_index.clear();
}

Mesh Mesh::Cube(const double & size){
	Mesh m;
	float offset = size/2;
	// Génération des vertices
	for(int i = 0; i < 8; i++)
		m.vertice(
			((i&4) == 4 ? 1 : -1) * offset,
			((i&2) == 2 ? 1 : -1) * offset,
			((i&1) == 1 ? 1 : -1) * offset
			);
	// Génération des faces
	m	.triangle(0, 1, 3)
		.triangle(0, 3, 2)
		.triangle(1, 5, 7)
		.triangle(1, 7, 3)
		.triangle(5, 4, 6)
		.triangle(5, 6, 7)
		.triangle(4, 0, 2)
		.triangle(4, 2, 6)
		.triangle(4, 5, 1)
		.triangle(4, 1, 0)
		.triangle(2, 3, 7)
		.triangle(2, 7, 6);
	return m;
}

Mesh Mesh::Sphere(const double & radius, const unsigned int lod){
	Mesh m;
	unsigned int nb_vert =	lod * lod;	// Nombre de vertex hormis le premier et le dernier
	Index v_last_index =	nb_vert + 1;	// Index du dernier vertex

	for(unsigned int i = 0; i < lod; i++){
		// Dessin des faces liées au sommet haut de la sphère
		Index 	actual = i * lod,
				next = (actual + lod) % nb_vert;
		m.triangle(	nb_vert, next, actual);
		// Dessin des vertexs et des portions de la sphère
		for(unsigned int j = 1; j <= lod; j++){
			double 	portion_x = (i / (double)lod) * (2 * MESH_PI),
					portion_y = - ((MESH_PI/(lod + 1)) * j) + (MESH_PI / 2),
					delta = cos(portion_y),
					v_y = sin(portion_y),
					v_x = cos(portion_x) * delta,
					v_z = sin(portion_x) * delta;
			Index start = m.vertice(v_x * radius, v_y * radius, v_z * radius);

			// Dessin des portions
			if(j % lod != 0){
				m	.triangle(start, (start + lod) % nb_vert, (start + lod + 1) % nb_vert )
					.triangle(start, (start + lod + 1) % nb_vert, start + 1 );
			}
		}
		// Dessin des faces liées au sommet bas de la sphère
		m.triangle( v_last_index, ((lod * i) - 1) % nb_vert, (lod * (i+1)) - 1 );
	}
	// Sommet haut de la sphère
	m.vertice(0,radius,0);
	// Sommet bas de la sphère
	m.vertice(0,-radius,0);

	return m;	
}