#include "include/includes.hpp"

int main(int argc, char** argv){

	/*
	Geo_Scene scene;

	Sphere s(Vector3(0,0,0), 5);
	scene << s << Plane(Vector3(0,-6,0), Vector3(0,1,0));
	
	
	// Plane p(Vector3(0,-6,0), Vector3(0,1,0));
	// scene(s);
	// scene(p);
	

	Ray r(Vector3(0,-10,0), Vector3(0,1,0));
	Hit h;

	std::cout << "Taille de la scène : " << scene.size() << std::endl;
	std::cout << "Touché (scène) ? : " << r(scene,h) << std::endl;
	std::cout << "Touché (sphère) ? : " << r(s,h) << std::endl;
	std::cout << "Point d'intersection : " << h.p << std::endl;
	std::cout << "Normale : " << h.n << std::endl;
	std::cout << "Distance : " << h.d << std::endl;
	*/
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

	Line l1(Vector2(-3.0, 3.0), Vector2(3.0, -3.0));
	// l1.Translate(Vector2(0.0, -3.0));
	Raycast2D ray(Vector2(-3.0, 0.0), Vector2(1.0, 0.0));
	RaycastHit2D hit;
	if(l1(ray, hit)){
		std::cout << "Origine : " << hit.origin << std::endl;
		std::cout << "Intersection : " << hit.point << std::endl;
		std::cout << "Normale : " << hit.normal.Normalized() << std::endl;
		std::cout << "Distance : " << hit.Distance() << std::endl;
	}else{
		std::cout << "Non touché" << std::endl;
	}
}