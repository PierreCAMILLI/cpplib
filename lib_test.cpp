#include "include/includes.hpp"

int main(int argc, char** argv){
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
	/*
	Triangulation t;
	t.ImportFile("tri/line0.tri");
	std::cout << "Nombre de vertices : " << t.GetVertices().size() << std::endl;
	std::cout << "Nombre de faces : " << t.GetFaces().size() << std::endl;
	t.ToMesh().ExportOBJ("mesh/triangulation.obj");
	*/
	/*
	Actor actor(1, "Mon acteur");
	actor.AddComponent(Renderer(5));
	std::cout << actor.GetComponent<Renderer>()->a << std::endl;
	*/

	Image im(100,100);
	const unsigned int cellSize = 10;
	for(unsigned int i = 0; i < im.GetWidth(); ++i){
		for(unsigned int j = 0; j < im.GetHeight(); ++j){
			int xCheck = (((int) floor(i / cellSize) % 2) == 0 ? 1 : -1);
			int yCheck = (((int) floor(j / cellSize) % 2) == 0 ? 1 : -1);
			if( xCheck * yCheck > 0)
				im(i,j) = Color::Red();
			else
				im(i,j) = Color::Blue();
		}
	}

	
	for(unsigned int i = 0; i < im.GetWidth(); ++i){
		im(i,i) = Color::Yellow();
	}
	
	im.Export("ImageTest.bmp");
	im.Release();
}