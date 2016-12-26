#pragma once

#include "includes.hpp"

template<typename T>
struct Vector2_t;

template<typename T>
struct Vector3_t;

template<typename T,unsigned int U>
class Matrix_{
	private:
		T* m;
	public:
		/**
		* Construit une matrice identitaire de taille U
		* */
		Matrix_<T,U>();
		/**
		* Libère la matrice en mémoire, non-fonctionnel
		* */
		~Matrix_<T,U>();
		/**
		* Construit une matrice de taille U et la remplie de la valeur n
		* */
		Matrix_<T,U>(const T& n);
		/**
		* Construit une matrice de taille U à partir du tableau _t
		* */
		Matrix_<T,U>(const T* const _t);
		/**
		* Construit une matrice de taille U à partir du tableau _t
		* */
		Matrix_<T,U>(T* const _t);
		/**
		* Construit une matrice de taille U à partir du tableau _t
		* */
		Matrix_<T,U>(T** const _t);
		/**
		* Construit une matrice de taille U à partir de la matrice _m
		* */
		Matrix_<T,U>(const Matrix_<T,U>& _m);
		/**
		* Retourne une copie de la matrice
		* */
		Matrix_<T,U> copy() const;
		/**
		* Libère la matrice en mémoire
		* */
		void release();
		/**
		* Retourne l'identité de la matrice de taille U
		* */
		static Matrix_<T,U> Identity();

		/**
		* Retourne la valeur de la matrice en (x,y)
		* */
		T& operator()(const unsigned int& x, const unsigned int& y);
		/**
		* Retourne la valeur de la matrice en (x,y)
		* */
		T operator()(const unsigned int& x, const unsigned int& y) const;
		/**
		* Retourne le produit des deux matrices
		* */
		Matrix_<T,U> operator*(const Matrix_<T,U>& _m) const;
		/**
		* Retourne la matrice dont les valeurs ont été multipliées par n
		* */
		Matrix_<T,U> operator*(const T& n) const;
		/**
		* Retourne la somme des deux matrices
		* */
		Matrix_<T,U> operator+(const Matrix_<T,U>& _m) const;
		/**
		* Retourne la matrice dont les valeurs ont été additionnées avec n
		* */
		Matrix_<T,U> operator+(const T& n) const;
		/**
		* Retourne la matrice "différenciée" de la matrice d'origine
		* */
		Matrix_<T,U> operator-() const;
		/**
		* Retourne la différence des deux matrices
		* */
		Matrix_<T,U> operator-(const Matrix_<T,U>& _m) const;
		/**
		* Retourne la matrice dont les valeurs ont été soustraites avec n
		* */
		Matrix_<T,U> operator-(const T& n) const;
		/**
		* Retourne la matrice dont les valeurs ont été divisées par n
		* */
		Matrix_<T,U> operator/(const T& n) const;
		/**
		* Indique si la matrice est identique avec l'autre matrice
		* */
		bool operator==(const Matrix_<T,U>& _m);
		/**
		* Indique si la matrice est différente de l'autre matrice
		* */
		bool operator!=(const Matrix_<T,U>& _m);
		
		/**
		* Retourne un tableau constant des données de la matrice
		* */
		const T* constData() const;
		/**
		* Retourne un tableau des données de la matrice
		* */
		T* data() const;
		/**
		* Retourne un tableau 2D des données de la matrice
		* */
		T** data2D() const;

		/**
		* Rempli la matrice avec la valeur n
		* */
		void fill(const T& n);
		/**
		* Rempli la matrice avec les valeurs dans _t
		* */
		void fill(const T* const _t);
		/**
		* Rempli la matrice avec les valeurs dans _t
		* */
		void fill(T* const _t);
		/**
		* Rempli la matrice avec les valeurs dans _t
		* */
		void fill(T** const _t);
		/**
		* Rempli la ligne r de la matrice avec la valeur n
		* */
		void fillRow(const unsigned int& r, const T& n);
		/**
		* Rempli la ligne r de la matrice avec les valeurs dans _t
		* */
		void fillRow(const unsigned int& r, const T* const _t);
		/**
		* Rempli la ligne r de la matrice avec les valeurs dans _t
		* */
		void fillRow(const unsigned int& r, T* const _t);
		/**
		* Rempli la colonne c de la matrice avec la valeur n
		* */
		void fillColumn(const unsigned int& c, const T& n);
		/**
		* Rempli la colonne c de la matrice avec les valeurs dans _t
		* */
		void fillColumn(const unsigned int& c, const T* const _t);
		/**
		* Rempli la colonne c de la matrice avec les valeurs dans _t
		* */
		void fillColumn(const unsigned int& c, T* const _t);
		/**
		* Inverse les cellules aux coordonnées (x1,y1) et (x2,y2)
		* */
		void switchPositions(const unsigned int& x1, const unsigned int& y1, const unsigned int& x2, const unsigned int& y2);

		/**
		* Transforme les valeurs de la matrice en celles de l'identité
		* */
		void setToIdentity();
		/**
		* Retourne la matrice privée de sa colonne x et de sa ligne y
		* */
		Matrix_<T,U-1> reduce(const unsigned int& x, const unsigned int& y) const;
		/**
		* Retourne le déterminant de la matrice
		* */
		T determinant() const;
		/**
		* Retourne la transposée de la matrice
		* */
		Matrix_<T,U> transpose() const;
		/**
		* Retourne l'inverse de la matrice
		* */
		Matrix_<T,U> invert() const;
		/**
		* Retourne la normale de la matrice
		* */
		Matrix_<T,U> normale() const;

		/**
		* Affiche la matrice entière
		* */
		void display();
		/**
		* Affiche la cellule (x,y) de la matrice
		* */
		void display(const unsigned int& x, const unsigned int& y);
		/**
		* Affiche la colonne x de la matrice
		* */
		void displayColumn(const unsigned int& x);
		/**
		* Affiche la ligne y de la matrice
		* */
		void displayRow(const unsigned int& y);
};

template<typename T>
Vector2_t<T> operator*(const Matrix_<T,2>& _m, const Vector2_t<T>& _v);

template<typename T>
Vector2_t<T> operator*(const Vector2_t<T>& _v, const Matrix_<T,2>& _m);

template<typename T>
Vector3_t<T> operator*(const Matrix_<T,3>& _m, const Vector3_t<T>& _v);

template<typename T>
Vector3_t<T> operator*(const Vector3_t<T>& _v, const Matrix_<T,3>& _m);

template<typename T>
class Matrix_<T,0>{
	private:
		T* m;
	public:
		Matrix_<T,0>(){}
		~Matrix_<T,0>(){}
		Matrix_<T,0>(const T& n);
		Matrix_<T,0>(const T* const _t){}
		Matrix_<T,0>(T* const _t){}
		Matrix_<T,0>(T** const _t){}
		Matrix_<T,0>(const Matrix_<T,0>& _m){}
		Matrix_<T,0> copy() const{	return Matrix_<T,0>();	}
		void release(){}
		static Matrix_<T,0> Identity(){	return Matrix_<T,0>();	}


		T& operator()(const unsigned int& x, const unsigned int& y){	return m[0];	}
		T operator()(const unsigned int& x, const unsigned int& y) const{	return m[0];	}
		Matrix_<T,0> operator*(const Matrix_<T,0>& _m) const{	return *this; }
		Matrix_<T,0> operator*(const T& n) const{	return *this;	}
		Matrix_<T,0> operator+(const Matrix_<T,0>& _m) const{	return *this;	}
		Matrix_<T,0> operator+(const T& n) const{	return *this;	}
		Matrix_<T,0> operator-() const{	return *this;	}
		Matrix_<T,0> operator-(const Matrix_<T,0>& _m) const{	return *this;	}
		Matrix_<T,0> operator-(const T& n) const{	return *this;	}
		Matrix_<T,0> operator/(const T& n) const{	return *this;	}
		bool operator==(const Matrix_<T,0>& _m){	return true;	}
		bool operator!=(const Matrix_<T,0>& _m){	return false;	}

		const T* constData() const{	return m;	}
		T* data() const{	return m;	}
		T** data2D() const{	return NULL; }

		void fill(const T& n){}
		void fill(const T* const _t){}
		void fill(T* const _t){}
		void fill(T** const _t){}
		void fillRow(const unsigned int& r, const T& n){}
		void fillRow(const unsigned int& r, const T* const _t){}
		void fillRow(const unsigned int& r, T* const _t){}
		void fillColumn(const unsigned int& c, const T& n){}
		void fillColumn(const unsigned int& c, const T* const _t){}
		void fillColumn(const unsigned int& c, T* const _t){}
		void switchPositions(const unsigned int& x1, const unsigned int& y1, const unsigned int& x2, const unsigned int& y2){}

		void setToIdentity(){}
		Matrix_<T,0> reduce(const unsigned int& x, const unsigned int& y) const{	return Matrix_<T,0>();	}
		T determinant() const{	return m[0];	}
		Matrix_<T,0> transpose() const{	return Matrix_<T,0>();	}
		Matrix_<T,0> invert() const{	return Matrix_<T,0>();	}
		Matrix_<T,0> normale() const{	return Matrix_<T,0>();	}

		void display(){}
		void display(const unsigned int& x, const unsigned int& y){}
		void displayColumn(const unsigned int& x){}
		void displayRow(const unsigned int& y){}
};

typedef Matrix_<double,2> Matrix2_;
typedef Matrix_<int,2> Matrix2i_;
typedef Matrix_<float,2> Matrix2f_;

typedef Matrix_<double,3> Matrix3_;
typedef Matrix_<int,3> Matrix3i_;
typedef Matrix_<float,3> Matrix3f_;

typedef Matrix_<double,4> Matrix4_;
typedef Matrix_<int,4> Matrix4i_;
typedef Matrix_<float,4> Matrix4f_;