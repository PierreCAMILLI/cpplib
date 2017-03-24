#pragma once

#include <string.h>

#include <limits>
#include <vector>

#include "mesh.hpp"

typedef unsigned int VerticeIndex;
typedef unsigned int FaceIndex;
typedef Vector3_t<VerticeIndex> TripleVerticesIndex;
typedef Vector3_t<FaceIndex> TripleFacesIndex;

constexpr VerticeIndex VERTICE_INDEX_INFINITY = std::numeric_limits<VerticeIndex>::infinity();

struct Face{
	TripleVerticesIndex vertices;
	TripleFacesIndex faces;

	Face(const Face& _face) = default;
	Face(	const VerticeIndex& _a, const VerticeIndex& _b, const VerticeIndex& _c,
			const FaceIndex& _x, const FaceIndex& _y, const FaceIndex& _z) :
			vertices(TripleVerticesIndex(_a, _b, _c)),
			faces(TripleFacesIndex(_x, _y, _z)){}

	VerticeIndex& operator[](const unsigned int& i){	return vertices[i];	}
	VerticeIndex operator[](const unsigned int& i) const{	return vertices[i];	}
	FaceIndex& operator()(const unsigned int& i){	return faces[i];	}
	FaceIndex operator()(const unsigned int& i) const{	return faces[i];	}

	bool HasVertice(VerticeIndex index){
		return 	vertices.x == index
			||	vertices.y == index
			||	vertices.z == index;		
	}

	bool HasInfiniteVertice(){	return HasVertice(VERTICE_INDEX_INFINITY);	}
};

typedef std::vector<Vector2_t<double> > TriangulationVertices;
typedef std::vector<Face> TriangulationFaces;

class Triangulation
{
	private:
		TriangulationVertices vertices;
		TriangulationFaces faces;

		void InsertInfiniteVertice();
		void InsertInFace(const Vector2_t<double>& vertice, const FaceIndex& face);

		// _a et _b vont de gauche à droite
		static bool IsUpside(const Vector2_t<double>& _o, const Vector2_t<double>& _a, const Vector2_t<double>& _b);
	public:
		Triangulation(){}
		Triangulation(const Triangulation& _triangulation) = default;

		void ImportFile(const std::string& file);
		Triangulation& AddVertice(const Vector2_t<double>& vertice);
		Mesh ToMesh() const;

		// Classe les indexes des vertices passés en paramètres dans le sens anti-horaire (inverse a et b si dans le sens horaire)
		void SortVertices(VerticeIndex& _a, VerticeIndex& _b, VerticeIndex& _c);
		// Indique si le vertex est dans la triangulation, retourne la face correspondante, -1 sinon
		FaceIndex IsInside(const Vector2_t<double>& vertice);
		// Indique si le vertex est dans la face
		bool IsInsideFace(const Vector2_t<double>& vertice, const FaceIndex& face);

		void Delaunay();
		void Crust();
};