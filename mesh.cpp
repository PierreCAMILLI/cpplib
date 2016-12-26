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

void Mesh::vertice(const double& x, const double& y, const double& z)
{
	vertice(Vector3_t<double>(x,y,z));
}

void Mesh::texture(const double& x, const double& y)
{
	texture(Vector2_t<double>(x,y));
}

void Mesh::normal(const double& x, const double& y, const double& z)
{
	normal(Vector3_t<double>(x,y,z));
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

bool Mesh::exportOBJ(const std::string & filename)
{
	std::ofstream ofs( filename );

	if ( !ofs.good() )
		return  false;

	ofs << "#OBJ file\n";

	return true;
}

void Mesh::merge(const Mesh& _m)
{
	for(MeshVerticesIndex::const_iterator it = _m.vertices_index.begin(); it != _m.vertices_index.end(); it++){
		vertices_index.push_back(*it + vertices.size());
	}
	for(MeshTexturesIndex::const_iterator it = _m.textures_index.begin(); it != _m.textures_index.end(); it++){
		textures_index.push_back(*it + textures.size());
	}
	for(MeshNormalsIndex::const_iterator it = _m.normals_index.begin(); it != _m.normals_index.end(); it++){
		normals_index.push_back(*it + normals.size());
	}

	vertices.insert(vertices.end(),vertices.begin(),vertices.end());
	textures.insert(textures.end(),textures.begin(),textures.end());
	normals.insert(normals.end(),normals.begin(),normals.end());
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

void Mesh::clear()
{
	vertices.clear();
	textures.clear();
	normals.clear();
	vertices_index.clear();
	textures_index.clear();
	normals_index.clear();
}