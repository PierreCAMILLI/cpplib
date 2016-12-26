#pragma once

#include "includes.hpp"
#include "vector.hpp"

template<typename T>
struct Vector2_t;

template<typename T>
struct Vector3_t;

template<typename T>
struct Point_t;

typedef unsigned int Index;
typedef std::vector<Vector3_t<double> > MeshVertices;
typedef std::vector<Vector2_t<double> > MeshTextures;
typedef std::vector<Vector3_t<double> > MeshNormals;

typedef std::vector<Index> MeshVerticesIndex;
typedef std::vector<Index> MeshTexturesIndex;
typedef std::vector<Index> MeshNormalsIndex;

class Mesh{
	private:
		
		MeshVertices vertices;
		MeshTextures textures;
		MeshNormals normals;

		MeshVerticesIndex vertices_index;
		MeshTexturesIndex textures_index;
		MeshNormalsIndex normals_index;

	public:

		Mesh() = default;
		Mesh(const std::string & filename){	importOBJ(filename);	}
		void release();

		MeshVertices & getVertices(){	return vertices;	}
		MeshTextures & getTextures(){	return textures;	}
		MeshNormals & getNormals(){	return normals;	}
		MeshVerticesIndex & getVerticesIndex(){	return vertices_index;	}
		MeshTexturesIndex & getTexturesIndex(){	return textures_index;	}
		MeshNormalsIndex & getNormalsIndex(){	return normals_index;	}

		MeshVertices const & getVertices() const{	return vertices;	}
		MeshTextures const & getTextures() const{	return textures;	}
		MeshNormals const & getNormals() const{	return normals;	}
		MeshVerticesIndex const & getVerticesIndex() const{	return vertices_index;	}
		MeshTexturesIndex const & getTexturesIndex() const{	return textures_index;	}
		MeshNormalsIndex const & getNormalsIndex() const{	return normals_index;	}

		void vertice(const Vector3_t<double> & _v){	vertices.push_back(_v);	}
		void vertice(const double& x, const double& y, const double& z);

		void texture(const Vector2_t<double> & _t){	textures.push_back(_t);	}
		void texture(const double& x, const double& y);

		void normal(const Vector3_t<double> & _t){	normals.push_back(_t);	}
		void normal(const double& x, const double& y, const double& z);

		void vertice_index(const Index & _vi){	vertices_index.push_back(_vi);	}
		void texture_index(const Index & _ti){	textures_index.push_back(_ti);	}
		void normal_index(const Index & _ni){	normals_index.push_back(_ni);	}

		bool importOBJ(const std::string & filename);
		bool exportOBJ(const std::string & filename);

		void merge(const Mesh & _m);
		void bounds(Point_t<double>& pmin, Point_t<double>& pmax);
		void clear();
};