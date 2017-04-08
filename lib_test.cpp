#include "include/includes.hpp"
#include <ctime>

int main(int argc, char** argv){
	
	// const double PI = 3.14159265359;
	// 2D
	Triangle2D t(Vector2(0.0, 0.0), Vector2(5.0, 0.0), Vector2(2.5, 5 * (sqrt(3)/2)));
	Timer::Reset();
	const Vector2	origin = Vector2(0.0, 1.0),
					center = t.Incenter();
	Raycast2D ray2(origin, center);
	RaycastHit2D hit2 = t(ray2);
	if(hit2){
		std::cout << hit2 << std::endl;
	}else{
		std::cout << "Non touché" << std::endl;
	}
	std::cout << "Temps d'exécution : " << Timer::Duration() << std::endl;

	std::cout << "///////////////////" << std::endl;

	// 3D
	Timer::Reset();
	Sphere s(Vector3(0,-1,-1), 2);
	Raycast ray(Vector3(-1,3,-1), Vector3(0,-1,0));
	RaycastHit hit;
	s(ray, hit);
	if(hit){
		std::cout << hit << std::endl;
	}else{
		std::cout << "Non touché" << std::endl;
	}
	std::cout << "Temps d'exécution : " << Timer::Duration() << std::endl;

	std::cout << "///////////////////" << std::endl;	

	Timer::Reset();
	Triangle t3(Vector3(0.0,0.0,0.0), Vector3(5.0, 5.0, 5.0), Vector3(10.0,0.0,0.0));
	Raycast ray3(Vector3(5.0,2.0,-1.0), Vector3(0.0,0.0,1.0));
	RaycastHit hit3;
	if(t3(ray3, hit3)){
		std::cout << hit3 << std::endl;
	}else{
		std::cout << "Non touché" << std::endl;
	}
	std::cout << "Temps d'exécution : " << Timer::Duration() << std::endl;

	std::cout << "///////////////////" << std::endl;	

	Timer::Reset();
	Plane plane(Vector3(0.0,0.0,0.0), Vector3(0.0, 1.0, 0.0));
	Raycast ray4(Vector3(0.0,-1.0,0.0), Vector3(0.0,1.0,0.0));
	RaycastHit hit4;
	if(plane(ray4, hit4)){
		std::cout << hit4 << std::endl;
	}else{
		std::cout << "Non touché" << std::endl;
	}
	std::cout << "Temps d'exécution : " << Timer::Duration() << std::endl;
}