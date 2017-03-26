#include "include/includes.hpp"

int main(int argc, char** argv){
	// Mesh::Cube(1.0).exportOBJ("cube.obj");
	// Mesh::Sphere(5.0, 100).exportOBJ("sphere.obj");
	// Mesh::Sphere(5.0, 100).merge(Mesh::Cube(1.0) + Vector3(10,0,0)).exportOBJ("merged.obj");

	/*
	Line l1(Vector2(-3.0, 0.0), Vector2(5.0, -2.5));
	Vector2 point(2.5, 5.0);
	std::cout << "Projection : " << l1.Projection(point) << std::endl;
	std::cout << "Distance : " << l1.Distance(point) << std::endl;

	Line l2(Vector2(0.0, -2.0), Vector2(2.0, 0.0));
	std::cout << l1.Cross(l2, point) << std::endl;
	std::cout << point << std::endl;
	*/

	/*
	Line l(Vector2(-3.0, 3.0), Vector2(3.0, -3.0));
	// l1.Translate(Vector2(0.0, -3.0));
	Circle c(Vector2(0.0, 1.0), 2.0);
	Raycast2D ray(Vector2(-3.0, 0.0), Vector2(2.0, 0.0));
	RaycastHit2D hit = c(ray);
	if(hit){
		std::cout << "Origine : " << hit.origin << std::endl;
		std::cout << "Intersection : " << hit.point << std::endl;
		std::cout << "Normale : " << hit.normal.Normalized() << std::endl;
		std::cout << "Distance : " << hit.Distance() << std::endl;
	}else{
		std::cout << "Non touché" << std::endl;
	}

	std::cout << l.IsInside(Vector2(-3.0, 3.0)) << std::endl;
	std::cout << l.IsInside(Vector2(0.0, 1.0)) << std::endl;
	*/

	Triangulation t;
	t.ImportFile("line0.tri");
	std::cout << "Nombre de vertices : " << t.GetVertices().size() << std::endl;
	std::cout << "Nombre de faces : " << t.GetFaces().size() << std::endl;
	t.ToMesh().ExportOBJ("triangulation.obj");
}