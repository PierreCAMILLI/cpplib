#pragma once

#include "includes.hpp"
#include "vector.hpp"

#define MESH_PI 3.14159265359

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

		Mesh(){}
		Mesh(const Mesh& _m) = default;
		Mesh(const std::string & filename){	ImportOBJ(filename);	}
		void Release();

		// Translation
		Mesh& operator+=(const Vector3_t<double> & t);
		Mesh operator+(const Vector3_t<double> & t){	return (*this) += t; }
		// Rescaling
		Mesh& operator*=(const double & s);
		Mesh& operator*=(const Vector3_t<double> & s);
		Mesh operator*(const double & s){	return (*this) *= s; }
		Mesh operator*(const Vector3_t<double> & s){	return (*this) *= s; }
		
		MeshVertices & GetVertices(){	return vertices;	}
		MeshTextures & GetTextures(){	return textures;	}
		MeshNormals & GetNormals(){	return normals;	}
		MeshVerticesIndex & GetVerticesIndex(){	return vertices_index;	}
		MeshTexturesIndex & GetTexturesIndex(){	return textures_index;	}
		MeshNormalsIndex & GetNormalsIndex(){	return normals_index;	}

		MeshVertices const & GetVertices() const{	return vertices;	}
		MeshTextures const & GetTextures() const{	return textures;	}
		MeshNormals const & GetNormals() const{	return normals;	}
		MeshVerticesIndex const & GetVerticesIndex() const{	return vertices_index;	}
		MeshTexturesIndex const & GetTexturesIndex() const{	return textures_index;	}
		MeshNormalsIndex const & GetNormalsIndex() const{	return normals_index;	}

		Index Vertice(const Vector3_t<double> & _v);
		Index Vertice(const double& x, const double& y, const double& z);

		Mesh& Texture(const Vector2_t<double> & _t);
		Mesh& Texture(const double& x, const double& y);

		Mesh& Normal(const Vector3_t<double> & _n);
		Mesh& Normal(const double& x, const double& y, const double& z);

		Mesh& VerticeIndex(const Index & _vi);
		Mesh& TextureIndex(const Index & _ti);
		Mesh& NormalIndex(const Index & _ni);

		//! Insère une face dont a, b, c sont les nouveaux sommets à insérer
		Mesh& Triangle(const Vector3_t<double> & a, const Vector3_t<double> & b, const Vector3_t<double> & c);
		//! Insère une face dont a, b, c sont les indices des sommets
		Mesh& Triangle(const Index & a, const Index & b, const Index & c);
		/*! Insère une face dont a, b, c sont les indices des sommets en comptant en partant du dernier
		\code
		m.Vertice(v0);
		m.Vertice(v1);
		m.Vertice(v2);
		m.Triangle_last(-3,-2,-1);
		\endcode
		*/
		Mesh& TriangleLast(const int & a, const int & b, const int & c);

		bool ImportOBJ(const std::string & filename);
		bool ExportOBJ(const std::string & filename, const double scale = 0.01);

		Mesh& Merge(const Mesh & _m);
		void Bounds(Point_t<double>& pmin, Point_t<double>& pmax);
		void Resize(const double& scale);
		void Clear();

		static Mesh Cube(const double & size);
		static Mesh Sphere(const double & radius, const unsigned int lod = 100);
};