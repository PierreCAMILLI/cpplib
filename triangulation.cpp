#include "include/triangulation.hpp"

void Triangulation::InsertInfiniteVertice(){
	vertices.push_back(Vector2_t<double>());
}

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
		// TODO
	}

	return (*this);
}

void Triangulation::SortVertices(VerticeIndex& _a, VerticeIndex& _b, VerticeIndex& _c){
	
}