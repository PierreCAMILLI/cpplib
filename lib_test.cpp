#include "include/includes.hpp"

int main(int argc, char** argv){
	/*
	float _m3[] = {-1, 2, 5,
					1, 2, 3,
				   -2, 8,10	};
	float _m4[] = {-1, 2, 5, 7,
					1, 2, 3,-2,
				   -2, 8,10, 7,
					9,-1, 6, 3 	};

	std::cout << "Matrix 2x2" << std::endl;
	Matrix2x2f mat2(5);
	mat2.fillColumn(0,2);
	mat2.display();

	Matrix2x2f mat2_1(3);
	mat2_1.fillColumn(0,1);
	mat2_1.display();

	(mat2 - mat2_1).display();

	std::cout << "Matrix 3x3" << std::endl;
	Matrix3x3f mat3(_m3);

	std::cout << "Matrix 4x4" << std::endl;
	Matrix4x4f mat4(_m4);

	std::cout << mat4.determinant() << std::endl;

	std::cout << "Matrix 2x4" << std::endl;
	Matrix2x4 mat24(3);
	Matrix4x2 mat42(3);
	(mat24 * mat42).display();
	(mat42 * mat24).display();

	std::cout << "Matrix3x4" << std::endl;
	Matrix3x4f mat34(5);
	(mat34 * mat3).display();
	
	std::cout << "Vector2" << std::endl;
	Vector2f vec2(5,3);
	Vector2f vec2_1(10,5);
	vec2.display();
	std::cout << "Changement par opérateur []" << std::endl;
	vec2[1] = 6;
	vec2.display();
	(mat2 * vec2).display();

	Matrixf<10,4> mat104;
	mat104.fillColumn(9, 5);
	mat104.display();
	(mat4 * mat104).display();
	std::cout << "Déterminant : " << (mat4 * mat104 * Matrixf<4,10>()) << std::endl;

	mat2.release();
	mat3.release();
	mat4.release();

	return 0;
	*/

	/*
	Curve c = Curve().point(0.0, 1.0).point(6.0, 10.0);

	std::cout << "Linear :" << std::endl;
	for(double i = -1.0; i <= 7.0; i+=0.5)
		std::cout << c.Linear(i) << std::endl;

	std::cout << "Sine :" << std::endl;
	for(double i = -1.0; i <= 7.0; i+=0.5)
		std::cout << c(i) << std::endl;
	*/

	Matrix2x2 m1(	5.0, 2.0,
					3.0, 4.0);
	Matrix3x3 m2(	5.0, 2.0, 8.0,
					3.0, 4.0, 6.0,
					7.0, 1.0, 9.0);
	/*
	Matrix4x4 m3(	5.0, 2.0, 8.0, 12.0,
					3.0, 5.0, 6.0, 10.0,
					7.0, 1.0, 9.0, 16.0,
					11.0,13.0,15.0,14.0);
	*/
	Matrix4x4 m3(	-1, 2, 5, 7,
					 1, 2, 3,-2,
				    -2, 8,10, 7,
					 9,-1, 6, 3);
	std::cout << m1.determinant() << std::endl;
	std::cout << m2.determinant() << std::endl;
	std::cout << m3.determinant() << std::endl;
}