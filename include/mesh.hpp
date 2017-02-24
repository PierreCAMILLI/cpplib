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

		Mesh() = default;
		Mesh(const std::string & filename){	importOBJ(filename);	}
		void release();

		// Translation
		Mesh& operator+=(const Vector3_t<double> & t);
		Mesh operator+(const Vector3_t<double> & t){	return (*this) += t; }
		// Rescaling
		Mesh& operator*=(const double & s);
		Mesh& operator*=(const Vector3_t<double> & s);
		Mesh operator*(const double & s){	return (*this) *= s; }
		Mesh operator*(const Vector3_t<double> & s){	return (*this) *= s; }
		
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

		Index vertice(const Vector3_t<double> & _v);
		Index vertice(const double& x, const double& y, const double& z);

		Mesh& texture(const Vector2_t<double> & _t);
		Mesh& texture(const double& x, const double& y);

		Mesh& normal(const Vector3_t<double> & _n);
		Mesh& normal(const double& x, const double& y, const double& z);

		Mesh& vertice_index(const Index & _vi);
		Mesh& texture_index(const Index & _ti);
		Mesh& normal_index(const Index & _ni);

		//! Insère une face dont a, b, c sont les nouveaux sommets à insérer
		Mesh& triangle(const Vector3_t<double> & a, const Vector3_t<double> & b, const Vector3_t<double> & c);
		//! Insère une face dont a, b, c sont les indices des sommets
		Mesh& triangle(const Index & a, const Index & b, const Index & c);
		/*! Insère une face dont a, b, c sont les indices des sommets en comptant en partant du dernier
		\code
		m.vertice(v0);
		m.vertice(v1);
		m.vertice(v2);
		m.triangle_last(-3,-2,-1);
		\endcode
		*/
		Mesh& triangle_last(const int & a, const int & b, const int & c);

		bool importOBJ(const std::string & filename);
		bool exportOBJ(const std::string & filename, const double scale = 0.01);

		Mesh& merge(const Mesh & _m);
		void bounds(Point_t<double>& pmin, Point_t<double>& pmax);
		void resize(const double& scale);
		void clear();

		static Mesh Cube(const double & size);
		static Mesh Sphere(const double & radius, const unsigned int lod = 100);
};