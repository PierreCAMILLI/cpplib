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
	Mesh::Sphere(5.0, 100).merge(Mesh::Cube(1.0) + Vector3(10,0,0)).exportOBJ("merged.obj");
}