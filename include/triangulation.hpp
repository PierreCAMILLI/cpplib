#pragma once

#include <string.h>

#include <limits>
#include <vector>

#include "mesh.hpp"

typedef unsigned int VerticeIndex;
typedef unsigned int FaceIndex;
typedef Vector3_t<VerticeIndex> TripleVerticesIndex;
typedef Vector3_t<FaceIndex> TripleFacesIndex;

constexpr VerticeIndex VERTICE_INDEX_INFINITY = std::numeric_limits<VerticeIndex>::max();

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

	bool HasVertice(const VerticeIndex& _index){
		return	(_index == vertices.x)
			||	(_index == vertices.y)
			||	(_index == vertices.z);	
	}

	bool HasInfiniteVertice(){	return HasVertice(VERTICE_INDEX_INFINITY);	}

	bool SetVerticeIndexTo(const VerticeIndex& v1, const VerticeIndex& v2){
		if(vertices.x == v1){	vertices.x = v2;	return true;	}
		if(vertices.y == v1){	vertices.y = v2;	return true;	}
		if(vertices.z == v1){	vertices.z = v2;	return true;	}
		return false;
	}

	bool SetFaceIndexTo(const FaceIndex& f1, const FaceIndex& f2){
		if(faces.x == f1){	faces.x = f2;	return true;	}
		if(faces.y == f1){	faces.y = f2;	return true;	}
		if(faces.z == f1){	faces.z = f2;	return true;	}
		return false;
	}
};

typedef std::vector<Vector2_t<double> > TriangulationVertices;
typedef std::vector<Face> TriangulationFaces;

class Triangulation
{
	private:
		TriangulationVertices vertices;
		TriangulationFaces faces;

		void InsertVerticeInFace(const VerticeIndex& vindex, const FaceIndex& findex);
		void InsertLastVerticeInFace(const FaceIndex& index){	InsertVerticeInFace(vertices.size() - 1, index);}
		void InsertLastVerticeOutsideTriangulation();

		// _a et _b vont de gauche à droite
		static bool IsUpside(const Vector2_t<double>& _o, const Vector2_t<double>& _a, const Vector2_t<double>& _b);
		bool IsUpside(const Vector2_t<double>& _o, const VerticeIndex& _a, const VerticeIndex& _b){	return IsUpside(_o, vertices[_a], vertices[_b]);	}
	public:

		class VerticesCirculator{
			private:
				Triangulation * const triangulation;
				VerticeIndex const vertice;
				FaceIndex currentFace;

			public:
				VerticesCirculator(Triangulation& _triangulation, const VerticeIndex& _vertice)
					: triangulation(&_triangulation), vertice(_vertice){
					for(FaceIndex i = 0; i < triangulation->GetFaces().size(); ++i){
						Face face = triangulation->GetFaces()[i];
						if(face.HasVertice(_vertice)){
							currentFace = i;
							break;
						}
					}
				}
				VerticesCirculator(const VerticesCirculator& _circulator) = default;

				VerticeIndex operator++() {
					Face face = triangulation->GetFaces()[currentFace];
							if(face.vertices.x == vertice)	currentFace = face.faces.x;
					else 	if(face.vertices.y == vertice)	currentFace = face.faces.y;
					else 	if(face.vertices.z == vertice)	currentFace = face.faces.z;
					return *(*this);
				}

				VerticeIndex operator++(int) {
					FaceIndex _temp = *(*this);
					++(*this);
					return _temp;
				}

				bool operator==(const VerticesCirculator& ci){
					return (currentFace == ci.currentFace)
						&& (vertice == ci.vertice)
						&& (triangulation == ci.triangulation);
				}

				bool operator!=(const VerticesCirculator& ci){	return !((*this) == ci);	}

				VerticesCirculator& operator=(const VerticesCirculator& _vc){
					currentFace = _vc.currentFace;
					return (*this);
				}

				VerticeIndex operator*() const{
					Face face = triangulation->GetFaces()[currentFace];
					if(face.vertices.x == vertice)	return face.vertices.y;
					if(face.vertices.y == vertice)	return face.vertices.z;
					return face.vertices.x;
				}

				Vector2_t<double>& GetVertice() const{
					return triangulation->GetVertices()[*(*this)];
				}
		};

		class FacesCirculator{
			private:
				Triangulation * const triangulation;
				VerticeIndex const vertice;
				FaceIndex currentFace;

			public:
				FacesCirculator(Triangulation& _triangulation, const VerticeIndex& _vertice)
					: triangulation(&_triangulation), vertice(_vertice){
					for(FaceIndex i = 0; i < triangulation->GetFaces().size(); ++i){
						Face face = triangulation->GetFaces()[i];
						if(face.HasVertice(_vertice)){
							currentFace = i;
							break;
						}
					}
				}
				FacesCirculator(const FacesCirculator& _circulator) = default;

				FaceIndex operator++() {
					Face face = GetFace();
							if(face.vertices.x == vertice)	currentFace = face.faces.x;
					else 	if(face.vertices.y == vertice)	currentFace = face.faces.y;
					else 	if(face.vertices.z == vertice)	currentFace = face.faces.z;
					return *(*this);
				}

				FaceIndex operator++(int) {
					FaceIndex _temp = *(*this);
					++(*this);
					return _temp;
				}

				bool operator==(const FacesCirculator& ci){
					return (currentFace == ci.currentFace)
						&& (vertice == ci.vertice)
						&& (triangulation == ci.triangulation);
				}

				bool operator!=(const FacesCirculator& ci){	return !((*this) == ci);	}

				FacesCirculator& operator=(const FacesCirculator& _fc){
					currentFace = _fc.currentFace;
					return (*this);
				}

				FaceIndex operator*() const{
					return currentFace;
				}

				Face& GetFace() const{
					return triangulation->GetFaces()[currentFace];
				}
		};

		Triangulation(){}
		Triangulation(const Triangulation& _triangulation) = default;

		operator Mesh() const{	return ToMesh();	};

		TriangulationVertices const & GetVertices() const{	return vertices;	}
		TriangulationFaces const & GetFaces() const{	return faces;	}

		TriangulationVertices& GetVertices(){	return vertices;	}
		TriangulationFaces& GetFaces(){	return faces;	}

		void ImportFile(const std::string& file);
		Triangulation& AddVertice(const Vector2_t<double>& vertice);
		void Clear();
		Mesh ToMesh() const;

		VerticesCirculator GetVerticesCirculator(const VerticeIndex& index){	return VerticesCirculator((*this), index);	}
		FacesCirculator GetFacesCirculator(const VerticeIndex& index){	return FacesCirculator((*this), index);	}

		// Classe les indexes des vertices passés en paramètres dans le sens anti-horaire (inverse a et b si dans le sens horaire)
		void SortVertices(VerticeIndex& _a, VerticeIndex& _b, VerticeIndex& _c);
		// Indique si le vertex est dans la triangulation
		bool IsInside(const Vector2_t<double>& vertice, FaceIndex& face);
		bool IsInside(const Vector2_t<double>& vertice){	FaceIndex fi;	return IsInside(vertice, fi);	}
		// Indique si le vertex est dans la face
		bool IsInsideFace(const Vector2_t<double>& vertice, const FaceIndex& index);

		void Delaunay();
		void Crust();
};