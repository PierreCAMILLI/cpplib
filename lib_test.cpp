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

	// std::cout << Color::Red() * 0.5f << std::endl;

	
	Image im(500,500);
	const Color	color = Color::Red(),
				backgroundColor = Color::Black();
	const unsigned int	dCenter = (im.GetWidth() / 2),
						maxDistance = dCenter * dCenter;

	for(unsigned int j = 0; j < im.GetHeight(); ++j){
		for(unsigned int i = 0; i < im.GetWidth(); ++i){
			unsigned int 	deltaX = i - dCenter,
							deltaY = j - dCenter,
							distance = (deltaX * deltaX) + (deltaY * deltaY);
			Color c = Color::Lerp(color, backgroundColor, (float)distance/maxDistance);
			im(i,j) = c;
		}
	}
	im.Export("ImageTest.bmp");
	
}