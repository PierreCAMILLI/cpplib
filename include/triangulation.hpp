#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>

#include <limits>
#include <vector>

#include "vector.hpp"

typedef int VerticeIndex;
typedef int FaceIndex;
typedef Vector3_t<VerticeIndex> TripleVerticesIndex;
typedef Vector3_t<FaceIndex> TripleFacesIndex;

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
};

constexpr int VERTICE_INDEX_INFINITY = std::numeric_limits<VerticeIndex>::infinity();

typedef std::vector<Vector2_t<double> > TriangulationVertices;
typedef std::vector<Face> TriangulationFaces;

class Triangulation
{
	private:
		TriangulationVertices vertices;
		TriangulationFaces faces;

		void InsertInfiniteVertice();
	public:
		Triangulation(){	InsertInfiniteVertice();	}
		Triangulation(const Triangulation& _triangulation) = default;

		void ImportFile(const std::string& file);
		Triangulation& AddVertice(const Vector2_t<double>& vertice);
		// Mesh ToMesh() const;

		// Classe les indexes des vertices passés en paramètres dans le sens anti-horaire
		void SortVertices(VerticeIndex& _a, VerticeIndex& _b, VerticeIndex& _c);

		void Delaunay();
		void Crust();
};