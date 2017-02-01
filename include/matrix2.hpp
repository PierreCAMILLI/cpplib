#pragma once

#include "includes.hpp"

template<typename T, unsigned int U, unsigned int V>
class Matrix_r{
	private:
		T* m;
	public:
		Matrix_r<T,U,V>();
		~Matrix_r<T,U,V>();
		Matrix_r<T,U,V>(const T n);
		Matrix_r<T,U,V>(const T* const _t);
		Matrix_r<T,U,V>(T* const _t);
		Matrix_r<T,U,V>(T** const _t);
		Matrix_r<T,U,V>(const Matrix_r<T,U,V>& _m);
		Matrix_r<T,U,V> copy() const;
		void release();
		static Matrix_r<T,U,V> Identity();

		Matrix_r<T,U,V>(const T m00, const T m10,
						const T m01, const T m11);
		Matrix_r<T,U,V>(const T m00, const T m10, const T m20,
						const T m01, const T m11, const T m21,
						const T m02, const T m12, const T m22);
		Matrix_r<T,U,V>(const T m00, const T m10, const T m20, const T m30,
						const T m01, const T m11, const T m21, const T m31,
						const T m02, const T m12, const T m22, const T m32,
						const T m03, const T m13, const T m23, const T m33);

		T& operator()(const unsigned int x, const unsigned int y);
		T operator()(const unsigned int x, const unsigned int y) const;
		Matrix_r<T,V,V> operator*(const Matrix_r<T,V,U>& _m) const;
		Matrix_r<T,U,V> operator*(const T n) const;
		Matrix_r<T,U,V> operator+(const Matrix_r<T,U,V>& _m) const;
		Matrix_r<T,U,V> operator+(const T n) const;
		Matrix_r<T,U,V> operator-() const;
		Matrix_r<T,U,V> operator-(const Matrix_r<T,U,V>& _m) const;
		Matrix_r<T,U,V> operator-(const T n) const;
		Matrix_r<T,U,V> operator/(const T n) const;
		bool operator==(const Matrix_r<T,U,V>& _m);
		bool operator!=(const Matrix_r<T,U,V>& _m);

		template<typename TT, unsigned int UU, unsigned int VV, unsigned int WW>
		friend Matrix_r<TT,WW,VV> operator*(const Matrix_r<TT,UU,VV>& _m1, const Matrix_r<TT,WW,UU>& _m2);
		template<typename TT>
		friend Vector2_t<TT> operator*(const Matrix_r<TT,2,2>& _m, const Vector2_t<TT>& _v);
		template<typename TT>
		friend Vector2_t<TT> operator*(const Vector2_t<TT>& _v, const Matrix_r<TT,2,2>& _m);
		template<typename TT>
		friend Vector3_t<TT> operator*(const Matrix_r<TT,3,3>& _m, const Vector3_t<TT>& _v);
		template<typename TT>
		friend Vector3_t<TT> operator*(const Vector3_t<TT>& _v, const Matrix_r<TT,3,3>& _m);
		template<typename TT>
		friend Point_t<TT> operator*(const Matrix_r<TT,3,3>& _m, const Point_t<TT>& _p);
		template<typename TT>
		friend Point_t<TT> operator*(const Point_t<TT>& _v, const Matrix_r<TT,3,3>& _m);
		template<typename TT>
		friend Vector4_t<TT> operator*(const Matrix_r<TT,4,4>& _m, const Vector4_t<TT>& _v);
		template<typename TT>
		friend Vector4_t<TT> operator*(const Vector4_t<TT>& _v, const Matrix_r<TT,4,4>& _m);
		template<typename TT,unsigned int UU, unsigned int VV>
		friend std::ostream& operator<<(std::ostream& o, const Matrix_r<TT,UU,VV>& _m);

		const T* constData() const;
		T* data() const;
		T** data2D() const;

		Matrix_r<T,U,V>& fill(const T n);
		Matrix_r<T,U,V>& fill(const T* const _t);
		Matrix_r<T,U,V>& fill(T* const _t);
		Matrix_r<T,U,V>& fill(T** const _t);
		Matrix_r<T,U,V>& fill(	const T m00, const T m10,
								const T m01, const T m11);
		Matrix_r<T,U,V>& fill(	const T m00, const T m10, const T m20,
								const T m01, const T m11, const T m21,
								const T m02, const T m12, const T m22);
		Matrix_r<T,U,V>& fill(	const T m00, const T m10, const T m20, const T m30,
								const T m01, const T m11, const T m21, const T m31,
								const T m02, const T m12, const T m22, const T m32,
								const T m03, const T m13, const T m23, const T m33);

		Matrix_r<T,U,V>& fillRow(const unsigned int r, const T n);
		Matrix_r<T,U,V>& fillRow(const unsigned int r, const T* const _t);
		Matrix_r<T,U,V>& fillRow(const unsigned int r, T* const _t);
		Matrix_r<T,U,V>& fillRow(const unsigned int r, const T m0, const T m1);
		Matrix_r<T,U,V>& fillRow(const unsigned int r, const T m0, const T m1, const T m2);
		Matrix_r<T,U,V>& fillRow(const unsigned int r, const T m0, const T m1, const T m2, const T m3);
		Matrix_r<T,U,V>& fillColumn(const unsigned int c, const T n);
		Matrix_r<T,U,V>& fillColumn(const unsigned int c, const T* const _t);
		Matrix_r<T,U,V>& fillColumn(const unsigned int c, T* const _t);
		Matrix_r<T,U,V>& fillColumn(const unsigned int c, const T m0, const T m1);
		Matrix_r<T,U,V>& fillColumn(const unsigned int c, const T m0, const T m1, const T m2);
		Matrix_r<T,U,V>& fillColumn(const unsigned int c, const T m0, const T m1, const T m2, const T m3);
		Matrix_r<T,U,V>& switchPositions(const unsigned int x1, const unsigned int y1, const unsigned int x2, const unsigned int y2);

		void setToIdentity();
		Matrix_r<T,U-1,V-1> reduce(const unsigned int x, const unsigned int y) const;
		Matrix_r<T,V,U> transpose() const;

		void display();
		void display(const unsigned int x, const unsigned int y);
		void displayColumn(const unsigned int x);
		void displayRow(const unsigned int y);
};

template<typename T,unsigned int U>
class Matrix_r<T,U,U>{
	private:
		T* m;
	public:
		//! Construit une matrice identitaire de taille U
		Matrix_r<T,U,U>();
		//! Libère la matrice en mémoire, non-fonctionnel
		~Matrix_r<T,U,U>();
		//! Construit une matrice de taille U et la remplie de la valeur n
		Matrix_r<T,U,U>(const T n);
		//! Construit une matrice de taille U à partir du tableau _t
		Matrix_r<T,U,U>(const T* const _t);
		//! Construit une matrice de taille U à partir du tableau _t
		Matrix_r<T,U,U>(T* const _t);
		//! Construit une matrice de taille U à partir du tableau _t
		Matrix_r<T,U,U>(T** const _t);
		//! Construit une matrice de taille U à partir de la matrice _m
		Matrix_r<T,U,U>(const Matrix_r<T,U,U>& _m);
		//! Retourne une copie de la matrice
		Matrix_r<T,U,U> copy() const;
		//! Libère la matrice en mémoire
		void release();
		//! Retourne l'identité de la matrice de taille U
		static Matrix_r<T,U,U> Identity();

		//! Construit une matrice contenant les valeurs indiquées en paramètres
		Matrix_r<T,U,U>(const T m00, const T m10,
						const T m01, const T m11);
		//! Construit une matrice contenant les valeurs indiquées en paramètres
		Matrix_r<T,U,U>(const T m00, const T m10, const T m20,
						const T m01, const T m11, const T m21,
						const T m02, const T m12, const T m22);
		//! Construit une matrice contenant les valeurs indiquées en paramètres
		Matrix_r<T,U,U>(const T m00, const T m10, const T m20, const T m30,
						const T m01, const T m11, const T m21, const T m31,
						const T m02, const T m12, const T m22, const T m32,
						const T m03, const T m13, const T m23, const T m33);

		//! Retourne la valeur de la matrice en (x,y)
		T& operator()(const unsigned int x, const unsigned int y);
		//! Retourne la valeur de la matrice en (x,y)
		T operator()(const unsigned int x, const unsigned int y) const;
		//! Retourne le produit des deux matrices
		Matrix_r<T,U,U> operator*(const Matrix_r<T,U,U>& _m) const;
		//! Retourne la matrice dont les valeurs ont été multipliées par n
		Matrix_r<T,U,U> operator*(const T n) const;
		//! Retourne la somme des deux matrices
		Matrix_r<T,U,U> operator+(const Matrix_r<T,U,U>& _m) const;
		//! Retourne la matrice dont les valeurs ont été additionnées avec n
		Matrix_r<T,U,U> operator+(const T n) const;
		//! Retourne la matrice "différenciée" de la matrice d'origine
		Matrix_r<T,U,U> operator-() const;
		//! Retourne la différence des deux matrices
		Matrix_r<T,U,U> operator-(const Matrix_r<T,U,U>& _m) const;
		//! Retourne la matrice dont les valeurs ont été soustraites avec n
		Matrix_r<T,U,U> operator-(const T n) const;
		//! Retourne la matrice dont les valeurs ont été divisées par n
		Matrix_r<T,U,U> operator/(const T n) const;
		//! Indique si la matrice est identique avec l'autre matrice
		bool operator==(const Matrix_r<T,U,U>& _m);
		//! Indique si la matrice est différente de l'autre matrice
		bool operator!=(const Matrix_r<T,U,U>& _m);
		
		//! Retourne un tableau constant des données de la matrice
		const T* constData() const;
		//! Retourne un tableau des données de la matrice
		T* data() const;
		//! Retourne un tableau 2D des données de la matrice
		T** data2D() const;

		//! Rempli la matrice avec la valeur n
		Matrix_r<T,U,U>& fill(const T n);
		//! Rempli la matrice avec les valeurs dans _t
		Matrix_r<T,U,U>& fill(const T* const _t);
		//! Rempli la matrice avec les valeurs dans _t
		Matrix_r<T,U,U>& fill(T* const _t);
		//! Rempli la matrice avec les valeurs dans _t
		Matrix_r<T,U,U>& fill(T** const _t);
		Matrix_r<T,U,U>& fill(	const T m00, const T m10,
								const T m01, const T m11);
		Matrix_r<T,U,U>& fill(	const T m00, const T m10, const T m20,
								const T m01, const T m11, const T m21,
								const T m02, const T m12, const T m22);
		Matrix_r<T,U,U>& fill(	const T m00, const T m10, const T m20, const T m30,
								const T m01, const T m11, const T m21, const T m31,
								const T m02, const T m12, const T m22, const T m32,
								const T m03, const T m13, const T m23, const T m33);
		//! Rempli la ligne r de la matrice avec la valeur n
		Matrix_r<T,U,U>& fillRow(const unsigned int r, const T n);
		//! Rempli la ligne r de la matrice avec les valeurs dans _t
		Matrix_r<T,U,U>& fillRow(const unsigned int r, const T* const _t);
		//! Rempli la ligne r de la matrice avec les valeurs dans _t
		Matrix_r<T,U,U>& fillRow(const unsigned int r, T* const _t);
		Matrix_r<T,U,U>& fillRow(const unsigned int r, const T m0, const T m1);
		Matrix_r<T,U,U>& fillRow(const unsigned int r, const T m0, const T m1, const T m2);
		Matrix_r<T,U,U>& fillRow(const unsigned int r, const T m0, const T m1, const T m2, const T m3);
		//! Rempli la colonne c de la matrice avec la valeur n
		Matrix_r<T,U,U>& fillColumn(const unsigned int c, const T n);
		//! Rempli la colonne c de la matrice avec les valeurs dans _t
		Matrix_r<T,U,U>& fillColumn(const unsigned int c, const T* const _t);
		//! Rempli la colonne c de la matrice avec les valeurs dans _t
		Matrix_r<T,U,U>& fillColumn(const unsigned int c, T* const _t);
		Matrix_r<T,U,U>& fillColumn(const unsigned int c, const T m0, const T m1);
		Matrix_r<T,U,U>& fillColumn(const unsigned int c, const T m0, const T m1, const T m2);
		Matrix_r<T,U,U>& fillColumn(const unsigned int c, const T m0, const T m1, const T m2, const T m3);
		//! Inverse les cellules aux coordonnées (x1,y1) et (x2,y2)
		Matrix_r<T,U,U>&  switchPositions(const unsigned int x1, const unsigned int y1, const unsigned int x2, const unsigned int y2);

		//! Transforme les valeurs de la matrice en celles de l'identité
		void setToIdentity();
		//! Retourne la matrice privée de sa colonne x et de sa ligne y
		Matrix_r<T,U-1,U-1> reduce(const unsigned int x, const unsigned int y) const;
		//! Retourne le déterminant de la matrice
		T determinant() const;
		//! Retourne la transposée de la matrice
		Matrix_r<T,U,U> transpose() const;
		//! Retourne l'inverse de la matrice
		Matrix_r<T,U,U> invert() const;
		//! Retourne la normale de la matrice
		Matrix_r<T,U,U> normale() const;

		//! Affiche la matrice entière
		void display();
		//! Affiche la cellule (x,y) de la matrice
		void display(const unsigned int x, const unsigned int y);
		//! Affiche la colonne x de la matrice
		void displayColumn(const unsigned int x);
		//! Affiche la ligne y de la matrice
		void displayRow(const unsigned int y);
};

template<typename TT, unsigned int UU, unsigned int VV, unsigned int WW>
Matrix_r<TT,WW,VV> operator*(const Matrix_r<TT,UU,VV>& _m1, const Matrix_r<TT,WW,UU>& _m2);

template<typename TT>
Vector2_t<TT> operator*(const Matrix_r<TT,2,2>& _m, const Vector2_t<TT>& _v);

template<typename TT>
Vector2_t<TT> operator*(const Vector2_t<TT>& _v, const Matrix_r<TT,2,2>& _m);

template<typename TT>
Vector3_t<TT> operator*(const Matrix_r<TT,3,3>& _m, const Vector3_t<TT>& _v);

template<typename TT>
Vector3_t<TT> operator*(const Vector3_t<TT>& _v, const Matrix_r<TT,3,3>& _m);

template<typename TT>
Point_t<TT> operator*(const Matrix_r<TT,3,3>& _m, const Point_t<TT>& _p);

template<typename TT>
Point_t<TT> operator*(const Point_t<TT>& _p, const Matrix_r<TT,3,3>& _m);

template<typename TT>
Vector4_t<TT> operator*(const Matrix_r<TT,4,4>& _m, const Vector4_t<TT>& _v);

template<typename TT>
Vector4_t<TT> operator*(const Vector3_t<TT>& _v, const Matrix_r<TT,4,4>& _m);

template<typename T>
class Matrix_r<T,0,0>{
	private:
		T* m;
	public:
		Matrix_r<T,0,0>(){}
		~Matrix_r<T,0,0>(){}
		Matrix_r<T,0,0>(const T n);
		Matrix_r<T,0,0>(const T* const _t){}
		Matrix_r<T,0,0>(T* const _t){}
		Matrix_r<T,0,0>(T** const _t){}
		Matrix_r<T,0,0>(const Matrix_r<T,0,0>& _m){}
		Matrix_r<T,0,0> copy() const{	Matrix_r<T,0,0>();	}
		void release(){}
		static Matrix_r<T,0,0> Identity(){	return Matrix_r<T,0,0>();	}


		T& operator()(const unsigned int x, const unsigned int y){	return m[0];	}
		T operator()(const unsigned int x, const unsigned int y) const{	return m[0];	}
		Matrix_r<T,0,0> operator*(const Matrix_r<T,0,0>& _m) const{	return *this; }
		Matrix_r<T,0,0> operator*(const T n) const{	return *this;	}
		Matrix_r<T,0,0> operator+(const Matrix_r<T,0,0>& _m) const{	return *this;	}
		Matrix_r<T,0,0> operator+(const T n) const{	return *this;	}
		Matrix_r<T,0,0> operator-() const{	return *this;	}
		Matrix_r<T,0,0> operator-(const Matrix_r<T,0,0>& _m) const{	return *this;	}
		Matrix_r<T,0,0> operator-(const T n) const{	return *this;	}
		Matrix_r<T,0,0> operator/(const T n) const{	return *this;	}
		bool operator==(const Matrix_r<T,0,0>& _m){	return true;	}
		bool operator!=(const Matrix_r<T,0,0>& _m){	return false;	}

		const T* constData() const{	return m;	}
		T* data() const{	return m;	}
		T** data2D() const{	return NULL; }

		Matrix_r<T,0,0>& fill(const T n){	return (*this);	}
		Matrix_r<T,0,0>& fill(const T* const _t){	return (*this);	}
		Matrix_r<T,0,0>& fill(T* const _t){	return (*this);	}
		Matrix_r<T,0,0>& fill(T** const _t){	return (*this);	}
		Matrix_r<T,0,0>& fill(	const T m00, const T m10,
								const T m01, const T m11){	return (*this);	};
		Matrix_r<T,0,0>& fill(	const T m00, const T m10, const T m20,
								const T m01, const T m11, const T m21,
								const T m02, const T m12, const T m22){	return (*this);	};
		Matrix_r<T,0,0>& fill(	const T m00, const T m10, const T m20, const T m30,
								const T m01, const T m11, const T m21, const T m31,
								const T m02, const T m12, const T m22, const T m32,
								const T m03, const T m13, const T m23, const T m33){	return (*this);	};
		Matrix_r<T,0,0>& fillRow(const unsigned int r, const T n){	return (*this);	}
		Matrix_r<T,0,0>& fillRow(const unsigned int r, const T* const _t){	return (*this);	}
		Matrix_r<T,0,0>& fillRow(const unsigned int r, T* const _t){	return (*this);	}
		Matrix_r<T,0,0>& fillRow(const unsigned int r, const T m0, const T m1){	return (*this);	}
		Matrix_r<T,0,0>& fillRow(const unsigned int r, const T m0, const T m1, const T m2){	return (*this);	}
		Matrix_r<T,0,0>& fillRow(const unsigned int r, const T m0, const T m1, const T m2, const T m3){	return (*this);	}
		Matrix_r<T,0,0>& fillColumn(const unsigned int c, const T n){	return (*this);	}
		Matrix_r<T,0,0>& fillColumn(const unsigned int c, const T* const _t){	return (*this);	}
		Matrix_r<T,0,0>& fillColumn(const unsigned int c, T* const _t){	return (*this);	}
		Matrix_r<T,0,0>& fillColumn(const unsigned int c, const T m0, const T m1){	return (*this);	}
		Matrix_r<T,0,0>& fillColumn(const unsigned int c, const T m0, const T m1, const T m2){	return (*this);	}
		Matrix_r<T,0,0>& fillColumn(const unsigned int c, const T m0, const T m1, const T m2, const T m3){	return (*this);	}
		Matrix_r<T,0,0>& switchPositions(const unsigned int x1, const unsigned int y1, const unsigned int x2, const unsigned int y2){	return (*this);	}

		void setToIdentity(){}
		Matrix_r<T,0,0> reduce(const unsigned int x, const unsigned int y) const{	return Matrix_r<T,0,0>();	}
		T determinant() const{	return m[0];	}
		Matrix_r<T,0,0> transpose() const{	return Matrix_r<T,0,0>();	}
		Matrix_r<T,0,0> invert() const{	return Matrix_r<T,0,0>();	}
		Matrix_r<T,0,0> normale() const{	return Matrix_r<T,0,0>();	}

		void display(){}
		void display(const unsigned int x, const unsigned int y){}
		void displayColumn(const unsigned int x){}
		void displayRow(const unsigned int y){}
};

/*
template <typename T>
class Matrix_r<T,2,2>{
	private:
		T* m;
	public:
		Matrix_r<T,2,2>(){}
		Matrix_r<T,2,2>(const T m00, const T m10,
						const T m01, const T m11);
};
*/

// ---------------------- CAS PARTICULIERS ----------------------- //

template<typename TT,unsigned int UU, unsigned int VV, unsigned int WW>
Matrix_r<TT,WW,VV> operator*(const Matrix_r<TT,UU,VV>& _m1, const Matrix_r<TT,WW,UU>& _m2){
	Matrix_r<TT,WW,VV> res;
	for(unsigned int i = 0; i < VV; i++)
		for(unsigned int j = 0; j < WW; j++){
			TT val = 0.0f;
			for(unsigned int k = 0; k < UU; k++)
				val += _m1(k,i) * _m2(j,k);
			res(j,i) = val;
		}
	return res;
}

template<typename TT>
Vector2_t<TT> operator*(const Matrix_r<TT,2,2>& _m, const Vector2_t<TT>& _v){
	return Vector2_t<TT>(
		(_m(0,0) * _v.x) + (_m(1,0) * _v.y),
		(_m(0,1) * _v.x) + (_m(1,1) * _v.y));
}

template<typename TT>
Vector2_t<TT> operator*(const Vector2_t<TT>& _v, const Matrix_r<TT,2,2>& _m){
	return Vector2_t<TT>(
		(_m(0,0) * _v.x) + (_m(0,1) * _v.y),
		(_m(1,0) * _v.x) + (_m(1,1) * _v.y));
}

template<typename TT>
Vector3_t<TT> operator*(const Matrix_r<TT,3,3>& _m, const Vector3_t<TT>& _v){
	return Vector3_t<TT>(
		(_m(0,0) * _v.x) + (_m(1,0) * _v.y) + (_m(2,0) * _v.z),
		(_m(0,1) * _v.x) + (_m(1,1) * _v.y) + (_m(2,1) * _v.z),
		(_m(0,2) * _v.x) + (_m(1,2) * _v.y) + (_m(2,2) * _v.z));
}

template<typename TT>
Vector3_t<TT> operator*(const Vector3_t<TT>& _v, const Matrix_r<TT,3,3>& _m){
	return Vector3_t<TT>(
		(_m(0,0) * _v.x) + (_m(0,1) * _v.y) + (_m(0,2) * _v.z),
		(_m(1,0) * _v.x) + (_m(1,1) * _v.y) + (_m(1,2) * _v.z),
		(_m(2,0) * _v.x) + (_m(2,1) * _v.y) + (_m(2,2) * _v.z));
}

template<typename TT>
Point_t<TT> operator*(const Matrix_r<TT,3,3>& _m, const Point_t<TT>& _p){
	return Point_t<TT>(
		(_m(0,0) * _p.x) + (_m(1,0) * _p.y) + (_m(2,0) * _p.z),
		(_m(0,1) * _p.x) + (_m(1,1) * _p.y) + (_m(2,1) * _p.z),
		(_m(0,2) * _p.x) + (_m(1,2) * _p.y) + (_m(2,2) * _p.z));
}

template<typename TT>
Point_t<TT> operator*(const Point_t<TT>& _p, const Matrix_r<TT,3,3>& _m){
	return Point_t<TT>(
		(_m(0,0) * _p.x) + (_m(0,1) * _p.y) + (_m(0,2) * _p.z),
		(_m(1,0) * _p.x) + (_m(1,1) * _p.y) + (_m(1,2) * _p.z),
		(_m(2,0) * _p.x) + (_m(2,1) * _p.y) + (_m(2,2) * _p.z));
}

template<typename TT>
Vector4_t<TT> operator*(const Matrix_r<TT,4,4>& _m, const Vector4_t<TT>& _v){
	return Vector4_t<TT>(
		(_m(0,0) * _v.x) + (_m(1,0) * _v.y) + (_m(2,0) * _v.z) + (_m(3,0) * _v.w),
		(_m(0,1) * _v.x) + (_m(1,1) * _v.y) + (_m(2,1) * _v.z) + (_m(3,1) * _v.w),
		(_m(0,2) * _v.x) + (_m(1,2) * _v.y) + (_m(2,2) * _v.z) + (_m(3,2) * _v.w),
		(_m(0,3) * _v.x) + (_m(1,3) * _v.y) + (_m(2,3) * _v.z) + (_m(3,3) * _v.w));
}

template<typename TT>
Vector4_t<TT> operator*(const Vector4_t<TT>& _v, const Matrix_r<TT,4,4>& _m){
	return Vector4_t<TT>(
		(_m(0,0) * _v.x) + (_m(0,1) * _v.y) + (_m(0,2) * _v.z) + (_m(0,3) * _v.w),
		(_m(1,0) * _v.x) + (_m(1,1) * _v.y) + (_m(1,2) * _v.z) + (_m(1,3) * _v.w),
		(_m(2,0) * _v.x) + (_m(2,1) * _v.y) + (_m(2,2) * _v.z) + (_m(2,3) * _v.w),
		(_m(3,0) * _v.x) + (_m(3,1) * _v.y) + (_m(3,2) * _v.z) + (_m(3,3) * _v.w));
}

template<typename TT,unsigned int UU, unsigned int VV>
std::ostream& operator<<(std::ostream& o, const Matrix_r<TT,UU,VV>& _m)
{
	o << std::endl;
    for(unsigned int i = 0; i < VV; i++){
    	for(unsigned int j = 0; j < UU; j++)
    		o << _m(j,i)<< "\t" ;
    	o << std::endl;
    }
    return o;
}

// ------------------ RECTANGULAR MATRIX ---------------------- //

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>::Matrix_r(){
	m = (T*) malloc(sizeof(T)*U*V);
	setToIdentity();
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>::Matrix_r(const T n){
	m = (T*) malloc(sizeof(T)*U*V);
	fill(n);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>::Matrix_r(const T* const _t){
	m = (T*) malloc(sizeof(T)*U*V);
	fill(_t);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>::Matrix_r(T* const _t){
	m = (T*) malloc(sizeof(T)*U*V);
	fill(_t);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>::Matrix_r(T** const _t){
	m = (T*) malloc(sizeof(T)*U*V);
	fill(_t);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>::Matrix_r(const Matrix_r<T,U,V>& _m){
	m = (T*) malloc(sizeof(T)*U*V);
	for(unsigned int i = 0; i < U*V; i++){
		m[i] = _m.m[i];
	}
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>::~Matrix_r<T,U,V>(){
	//	release();
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V> Matrix_r<T,U,V>::copy() const{
	Matrix_r<T,U,V> res;
	for(unsigned int i = 0; i < U*V; i++)
		res.m[i] = m[i];
	return res;
}

template<typename T,unsigned int U, unsigned int V>
void Matrix_r<T,U,V>::release(){
	free(m);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V> Matrix_r<T,U,V>::Identity(){
	return Matrix_r<T,U,V>();
}


template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>::Matrix_r(	const T m00, const T m10,
							const T m01, const T m11){
	assert(U >= 2);
	assert(V >= 2);
	m = (T*) malloc(sizeof(T)*U*V);
	fill(m00, m10,
		 m01, m11);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>::Matrix_r(	const T m00, const T m10, const T m20,
							const T m01, const T m11, const T m21,
							const T m02, const T m12, const T m22){
	assert(U >= 3);
	assert(V >= 3);
	m = (T*) malloc(sizeof(T)*U*V);
	fill(m00, m10, m20,
		 m01, m11, m21,
		 m02, m12, m22);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>::Matrix_r(	const T m00, const T m10, const T m20, const T m30,
							const T m01, const T m11, const T m21, const T m31,
							const T m02, const T m12, const T m22, const T m32,
							const T m03, const T m13, const T m23, const T m33){
	assert(U >= 4);
	assert(V >= 4);
	m = (T*) malloc(sizeof(T)*U*V);
	fill(m00, m10, m20, m30,
		 m01, m11, m21, m31,
		 m02, m12, m22, m32,
		 m03, m13, m23, m33);
}


template<typename T,unsigned int U, unsigned int V>
T& Matrix_r<T,U,V>::operator()(const unsigned int x, const unsigned int y){
	assert(x < U);
	assert(y < V);
	return m[x + y*U];
}

template<typename T,unsigned int U, unsigned int V>
T Matrix_r<T,U,V>::operator()(const unsigned int x, const unsigned int y) const{
	assert(x < U);
	assert(y < V);
	return m[x + y*U];
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,V,V> Matrix_r<T,U,V>::operator*(const Matrix_r<T,V,U>& _m) const{
	Matrix_r<T,V,V> res;
	for(unsigned int i = 0; i < V; i++)
		for(unsigned int j = 0; j < V; j++){
			T val = 0.0f;
			for(unsigned int k = 0; k < U; k++)
				val += (*this)(k,i) * _m(j,k);
			res(j,i) = val;
		}
	return res;
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V> Matrix_r<T,U,V>::operator*(const T n) const{
	Matrix_r<T,U,V> res;
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < V; j++)
			res(i,j) = (*this)(i,j) * n;
	return res;
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V> Matrix_r<T,U,V>::operator+(const Matrix_r<T,U,V>& _m) const{
	Matrix_r<T,U,V> res;
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < V; j++)
			res(i,j) = (*this)(i,j) + _m(i,j);
	return res;
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V> Matrix_r<T,U,V>::operator+(const T n) const{
	Matrix_r<T,U,V> res;
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < V; j++)
			res(i,j) = (*this)(i,j) + n;
	return res;
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V> Matrix_r<T,U,V>::operator-() const{
	Matrix_r<T,U,V> res;
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < V; j++)
			res(i,j) = -(*this)(i,j);
	return res;
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V> Matrix_r<T,U,V>::operator-(const Matrix_r<T,U,V>& _m) const{
	Matrix_r<T,U,V> res;
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < V; j++)
			res(i,j) = (*this)(i,j) - _m(i,j);
	return res;
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V> Matrix_r<T,U,V>::operator-(const T n) const{
	return (*this) + (-n);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V> Matrix_r<T,U,V>::operator/(const T n) const{
	return (*this) * (1/n);
}

template<typename T,unsigned int U, unsigned int V>
bool Matrix_r<T,U,V>::operator==(const Matrix_r<T,U,V>& _m){
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < V; j++)
			if((*this)(i,j) != _m(i,j))
				return false;
	return true;
}

template<typename T,unsigned int U, unsigned int V>
bool Matrix_r<T,U,V>::operator!=(const Matrix_r<T,U,V>& _m){
	return !((*this) == _m);
}


template<typename T,unsigned int U, unsigned int V>
const T* Matrix_r<T,U,V>::constData() const{
	return m;
}

template<typename T,unsigned int U, unsigned int V>
T* Matrix_r<T,U,V>::data() const{
	return m;
}

template<typename T,unsigned int U, unsigned int V>
T** Matrix_r<T,U,V>::data2D() const{
	T** res = (T**) malloc(V * sizeof(T*));
	for(unsigned int i = 0; i < V; i++){
		res[i] = (T*) malloc(U * sizeof(T));
		for(unsigned int j = 0; j < U; j++)
			res[i][j] = (*this)(j,i);
	}
	return res;
}


template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fill(const T n) {
	for(unsigned int i = 0; i < U * V; i++)
		m[i] = n;
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fill(const T* const _t) {
	for(unsigned int i = 0; i < U * V; i++)
		m[i] = _t[i];
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fill(T* const _t) {
	for(unsigned int i = 0; i < U * V; i++)
		m[i] = _t[i];
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fill(T** const _t) {
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < V; j++)
			(*this)(i,j) = _t[j][i];
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fill(	const T m00, const T m10,
						const T m01, const T m11){
	(*this)(0,0) = m00;	(*this)(1,0) = m10;
	(*this)(0,1) = m01;	(*this)(1,1) = m11;
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fill(	const T m00, const T m10, const T m20,
						const T m01, const T m11, const T m21,
						const T m02, const T m12, const T m22){

	(*this)(0,0) = m00;	(*this)(1,0) = m10;	(*this)(2,0) = m20;
	(*this)(0,1) = m01;	(*this)(1,1) = m11;	(*this)(2,1) = m21;
	(*this)(0,2) = m02;	(*this)(1,2) = m12;	(*this)(2,1) = m22;
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fill(	const T m00, const T m10, const T m20, const T m30,
						const T m01, const T m11, const T m21, const T m31,
						const T m02, const T m12, const T m22, const T m32,
						const T m03, const T m13, const T m23, const T m33){
	(*this)(0,0) = m00;	(*this)(1,0) = m10;	(*this)(2,0) = m20;	(*this)(2,0) = m30;
	(*this)(0,1) = m01;	(*this)(1,1) = m11;	(*this)(2,1) = m21;	(*this)(2,1) = m31;
	(*this)(0,2) = m02;	(*this)(1,2) = m12;	(*this)(2,1) = m22;	(*this)(2,1) = m32;
	(*this)(0,2) = m03;	(*this)(1,2) = m13;	(*this)(2,1) = m23;	(*this)(2,1) = m33;
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fillRow(const unsigned int r, const T n) {
	for(unsigned int i = 0; i < U; i++)
		(*this)(i,r) = n;
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fillRow(const unsigned int r, const T* const _t) {
	for(unsigned int i = 0; i < U; i++)
		(*this)(i,r) = _t[i];
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fillRow(const unsigned int r, T* const _t) {
	for(unsigned int i = 0; i < U; i++)
		(*this)(i,r) = _t[i];
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fillRow(const unsigned int r, const T m0, const T m1){
	(*this)(0,r) = m0;	(*this)(1,r) = m1;
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fillRow(const unsigned int r, const T m0, const T m1, const T m2){
	(*this)(0,r) = m0;	(*this)(1,r) = m1;	(*this)(2,r) = m2;
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fillRow(const unsigned int r, const T m0, const T m1, const T m2, const T m3){
	(*this)(0,r) = m0;	(*this)(1,r) = m1;	(*this)(2,r) = m2;	(*this)(3,r) = m3;
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fillColumn(const unsigned int c, const T n) {
	for(unsigned int i = 0; i < V; i++)
		(*this)(c,i) = n;
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fillColumn(const unsigned int c, const T* const _t) {
	for(unsigned int i = 0; i < V; i++)
		(*this)(c,i) = _t[i];
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fillColumn(const unsigned int c, T* const _t) {
	for(unsigned int i = 0; i < V; i++)
		(*this)(c,i) = _t[i];
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fillColumn(const unsigned int c, const T m0, const T m1){
	(*this)(c,0) = m0;	(*this)(c,1) = m1;
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fillColumn(const unsigned int c, const T m0, const T m1, const T m2){
	(*this)(c,0) = m0;	(*this)(c,1) = m1;	(*this)(c,2) = m2;
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::fillColumn(const unsigned int c, const T m0, const T m1, const T m2, const T m3){
	(*this)(c,0) = m0;	(*this)(c,1) = m1;	(*this)(c,2) = m2;	(*this)(c,3) = m3;
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U,V>& Matrix_r<T,U,V>::switchPositions(const unsigned int x1, const unsigned int y1, const unsigned int x2, const unsigned int y2){
	T temp = (*this)(x1,y1);
	(*this)(x1,y1) = (*this)(x2,y2);
	(*this)(x2,y2) = temp;
	return (*this);
}

template<typename T,unsigned int U, unsigned int V>
void Matrix_r<T,U,V>::setToIdentity(){
	fill(0.0f);
	unsigned int W = (U < V ? U : V);
	for(unsigned int i = 0; i < W; i++)
		(*this)(i,i) = 1;
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,U-1,V-1> Matrix_r<T,U,V>::reduce(const unsigned int x, const unsigned int y) const{
	Matrix_r<T,U-1,V-1> res;
	for(unsigned int i = 0; i < U-1; i++)
		for(unsigned int j = 0; j < V-1; j++){
			unsigned int xx = i + (i >= x ? 1 : 0);
			unsigned int yy = j + (j >= y ? 1 : 0);
			res(i,j) = (*this)(xx,yy);
		}
	return res;
}

template<typename T,unsigned int U, unsigned int V>
Matrix_r<T,V,U> Matrix_r<T,U,V>::transpose() const{
	Matrix_r<T,V,U> res;
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < V; j++)
			res(j,i) = (*this)(i,j);
	return res;
}

template<typename T,unsigned int U, unsigned int V>
void Matrix_r<T,U,V>::display(){
	for(unsigned int j = 0; j < V; j++){
		for(unsigned int i = 0; i < U; i++)
			std::cout << (*this)(i,j) << "\t";
		std::cout << std::endl;
	}
}

template<typename T,unsigned int U, unsigned int V>
void Matrix_r<T,U,V>::display(const unsigned int x, const unsigned int y){
	std::cout << (*this)(x,y) << std::flush;
}

template<typename T,unsigned int U, unsigned int V>
void Matrix_r<T,U,V>::displayColumn(const unsigned int x){
	for(unsigned int i = 0; i < V; i++)
		std::cout << (*this)(x,i) << std::endl;
	std::cout << std::endl;
}

template<typename T,unsigned int U, unsigned int V>
void Matrix_r<T,U,V>::displayRow(const unsigned int y){
	for(unsigned int i = 0; i < U; i++)
		std::cout << (*this)(i,y) << "\t";
	std::cout << std::endl;
}

// ------------------ SQUARE MATRIX ---------------------- //

template<typename T,unsigned int U>
Matrix_r<T,U,U>::Matrix_r(){
	m = (T*) malloc(sizeof(T)*U*U);
	setToIdentity();
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>::Matrix_r(const T n){
	m = (T*) malloc(sizeof(T)*U*U);
	fill(n);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>::Matrix_r(const T* const _t){
	m = (T*) malloc(sizeof(T)*U*U);
	fill(_t);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>::Matrix_r(T* const _t){
	m = (T*) malloc(sizeof(T)*U*U);
	fill(_t);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>::Matrix_r(T** const _t){
	m = (T*) malloc(sizeof(T)*U*U);
	fill(_t);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>::Matrix_r(const Matrix_r<T,U,U>& _m){
	m = (T*) malloc(sizeof(T)*U*U);
	for(unsigned int i = 0; i < U*U; i++)
		m[i] = _m.m[i];
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>::~Matrix_r<T,U,U>(){
	//	release();
}

template<typename T,unsigned int U>
Matrix_r<T,U,U> Matrix_r<T,U,U>::copy() const{
	Matrix_r<T,U,U> res;
	for(unsigned int i = 0; i < U*U; i++)
		res.m[i] = m[i];
	return res;
}

template<typename T,unsigned int U>
void Matrix_r<T,U,U>::release(){
	free(m);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U> Matrix_r<T,U,U>::Identity(){
	return Matrix_r<T,U,U>();
}


template<typename T,unsigned int U>
Matrix_r<T,U,U>::Matrix_r(	const T m00, const T m10,
							const T m01, const T m11){
	assert(U >= 2);
	m = (T*) malloc(sizeof(T)*U*U);
	fill(m00, m10,
		 m01, m11);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>::Matrix_r(	const T m00, const T m10, const T m20,
							const T m01, const T m11, const T m21,
							const T m02, const T m12, const T m22){
	assert(U >= 3);
	m = (T*) malloc(sizeof(T)*U*U);
	fill(m00, m10, m20,
		 m01, m11, m21,
		 m02, m12, m22);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>::Matrix_r(	const T m00, const T m10, const T m20, const T m30,
							const T m01, const T m11, const T m21, const T m31,
							const T m02, const T m12, const T m22, const T m32,
							const T m03, const T m13, const T m23, const T m33){
	assert(U >= 4);
	m = (T*) malloc(sizeof(T)*U*U);
	fill(m00, m10, m20, m30,
		 m01, m11, m21, m31,
		 m02, m12, m22, m32,
		 m03, m13, m23, m33);
}


template<typename T,unsigned int U>
T& Matrix_r<T,U,U>::operator()(const unsigned int x, const unsigned int y){
	assert(x < U);
	assert(y < U);
	return m[x + y*U];
}

template<typename T,unsigned int U>
T Matrix_r<T,U,U>::operator()(const unsigned int x, const unsigned int y) const{
	assert(x < U);
	assert(y < U);
	return m[x + y*U];
}

template<typename T,unsigned int U>
Matrix_r<T,U,U> Matrix_r<T,U,U>::operator*(const Matrix_r<T,U,U>& _m) const{
	Matrix_r<T,U,U> res;
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < U; j++){
			T val = 0.0f;
			for(unsigned int k = 0; k < U; k++)
				val += (*this)(k,i) * _m(j,k);
			res(j,i) = val;
		}
	return res;
}

template<typename T,unsigned int U>
Matrix_r<T,U,U> Matrix_r<T,U,U>::operator*(const T n) const{
	Matrix_r<T,U,U> res;
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < U; j++)
			res(i,j) = (*this)(i,j) * n;
	return res;
}

template<typename T,unsigned int U>
Matrix_r<T,U,U> Matrix_r<T,U,U>::operator+(const Matrix_r<T,U,U>& _m) const{
	Matrix_r<T,U,U> res;
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < U; j++)
			res(i,j) = (*this)(i,j) + _m(i,j);
	return res;
}

template<typename T,unsigned int U>
Matrix_r<T,U,U> Matrix_r<T,U,U>::operator+(const T n) const{
	Matrix_r<T,U,U> res;
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < U; j++)
			res(i,j) = (*this)(i,j) + n;
	return res;
}

template<typename T,unsigned int U>
Matrix_r<T,U,U> Matrix_r<T,U,U>::operator-() const{
	Matrix_r<T,U,U> res;
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < U; j++)
			res(i,j) = -(*this)(i,j);
	return res;
}

template<typename T,unsigned int U>
Matrix_r<T,U,U> Matrix_r<T,U,U>::operator-(const Matrix_r<T,U,U>& _m) const{
	Matrix_r<T,U,U> res;
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < U; j++)
			res(i,j) = (*this)(i,j) - _m(i,j);
	return res;
}

template<typename T,unsigned int U>
Matrix_r<T,U,U> Matrix_r<T,U,U>::operator-(const T n) const{
	return (*this) + (-n);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U> Matrix_r<T,U,U>::operator/(const T n) const{
	return (*this) * (1/n);
}

template<typename T,unsigned int U>
bool Matrix_r<T,U,U>::operator==(const Matrix_r<T,U,U>& _m){
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < U; j++)
			if((*this)(i,j) != _m(i,j))
				return false;
	return true;
}

template<typename T,unsigned int U>
bool Matrix_r<T,U,U>::operator!=(const Matrix_r<T,U,U>& _m){
	return !((*this) == _m);
}


template<typename T,unsigned int U>
const T* Matrix_r<T,U,U>::constData() const{
	return m;
}

template<typename T,unsigned int U>
T* Matrix_r<T,U,U>::data() const{
	return m;
}

template<typename T,unsigned int U>
T** Matrix_r<T,U,U>::data2D() const{
	T** res = (T**) malloc(U * sizeof(T*));
	for(unsigned int i = 0; i < U; i++){
		res[i] = (T*) malloc(U * sizeof(T));
		for(unsigned int j = 0; j < U; j++)
			res[i][j] = (*this)(j,i);
	}
	return res;
}


template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fill(const T n) {
	for(unsigned int i = 0; i < U * U; i++)
		m[i] = n;
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fill(const T* const _t) {
	for(unsigned int i = 0; i < U * U; i++)
		m[i] = _t[i];
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fill(T* const _t) {
	for(unsigned int i = 0; i < U * U; i++)
		m[i] = _t[i];
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fill(T** const _t) {
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < U; j++)
			(*this)(i,j) = _t[j][i];
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fill(	const T m00, const T m10,
										const T m01, const T m11){
	(*this)(0,0) = m00;	(*this)(1,0) = m10;
	(*this)(0,1) = m01;	(*this)(1,1) = m11;
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fill(	const T m00, const T m10, const T m20,
										const T m01, const T m11, const T m21,
										const T m02, const T m12, const T m22){
	(*this)(0,0) = m00;	(*this)(1,0) = m10;	(*this)(2,0) = m20;
	(*this)(0,1) = m01;	(*this)(1,1) = m11;	(*this)(2,1) = m21;
	(*this)(0,2) = m02;	(*this)(1,2) = m12;	(*this)(2,1) = m22;
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fill(	const T m00, const T m10, const T m20, const T m30,
										const T m01, const T m11, const T m21, const T m31,
										const T m02, const T m12, const T m22, const T m32,
										const T m03, const T m13, const T m23, const T m33){
	(*this)(0,0) = m00;	(*this)(1,0) = m10;	(*this)(2,0) = m20;	(*this)(3,0) = m30;
	(*this)(0,1) = m01;	(*this)(1,1) = m11;	(*this)(2,1) = m21;	(*this)(3,1) = m31;
	(*this)(0,2) = m02;	(*this)(1,2) = m12;	(*this)(2,2) = m22;	(*this)(3,2) = m32;
	(*this)(0,3) = m03;	(*this)(1,3) = m13;	(*this)(2,3) = m23;	(*this)(3,3) = m33;
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fillRow(const unsigned int r, const T n) {
	for(unsigned int i = 0; i < U; i++)
		(*this)(i,r) = n;
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fillRow(const unsigned int r, const T* const _t) {
	for(unsigned int i = 0; i < U; i++)
		(*this)(i,r) = _t[i];
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fillRow(const unsigned int r, T* const _t) {
	for(unsigned int i = 0; i < U; i++)
		(*this)(i,r) = _t[i];
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fillRow(const unsigned int r, const T m0, const T m1){
	(*this)(0,r) = m0;	(*this)(1,r) = m1;
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fillRow(const unsigned int r, const T m0, const T m1, const T m2){
	(*this)(0,r) = m0;	(*this)(1,r) = m1;	(*this)(2,r) = m2;
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fillRow(const unsigned int r, const T m0, const T m1, const T m2, const T m3){
	(*this)(0,r) = m0;	(*this)(1,r) = m1;	(*this)(2,r) = m2;	(*this)(3,r) = m3;
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fillColumn(const unsigned int c, const T n) {
	for(unsigned int i = 0; i < U; i++)
		(*this)(c,i) = n;
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fillColumn(const unsigned int c, const T* const _t) {
	for(unsigned int i = 0; i < U; i++)
		(*this)(c,i) = _t[i];
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fillColumn(const unsigned int c, T* const _t) {
	for(unsigned int i = 0; i < U; i++)
		(*this)(c,i) = _t[i];
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fillColumn(const unsigned int c, const T m0, const T m1){
	(*this)(c,0) = m0;	(*this)(c,1) = m1;
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fillColumn(const unsigned int c, const T m0, const T m1, const T m2){
	(*this)(c,0) = m0;	(*this)(c,1) = m1;	(*this)(c,2) = m2;
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::fillColumn(const unsigned int c, const T m0, const T m1, const T m2, const T m3){
	(*this)(c,0) = m0;	(*this)(c,1) = m1;	(*this)(c,2) = m2;	(*this)(c,3) = m3;
	return (*this);
}

template<typename T,unsigned int U>
Matrix_r<T,U,U>& Matrix_r<T,U,U>::switchPositions(const unsigned int x1, const unsigned int y1, const unsigned int x2, const unsigned int y2){
	T temp = (*this)(x1,y1);
	(*this)(x1,y1) = (*this)(x2,y2);
	(*this)(x2,y2) = temp;
	return (*this);
}

template<typename T,unsigned int U>
void Matrix_r<T,U,U>::setToIdentity(){
	fill(0.0f);
	for(unsigned int i = 0; i < U; i++)
		(*this)(i,i) = 1;
}

template<typename T,unsigned int U>
Matrix_r<T,U-1,U-1> Matrix_r<T,U,U>::reduce(const unsigned int x, const unsigned int y) const{
	Matrix_r<T,U-1,U-1> res;
	for(unsigned int i = 0; i < U-1; i++)
		for(unsigned int j = 0; j < U-1; j++){
			unsigned int xx = i + (i >= x ? 1 : 0);
			unsigned int yy = j + (j >= y ? 1 : 0);
			res(i,j) = (*this)(xx,yy);
		}
	return res;
}

template<typename T,unsigned int U>
T Matrix_r<T,U,U>::determinant() const{
	// Cas où la matrice est de taille 1 ou 2
	if(U == 1)
		return m[0];
	if(U == 2)
		return m[0]*m[3] - m[1]*m[2];
	T res = 0.0f;
	for(unsigned int i = 0; i < U; i++){
		Matrix_r<T,U-1,U-1> mat = reduce(i,0);
		res += ((i&1) == 1 ? -1 : 1) * m[i] * mat.determinant();
	}
	return res;
}

template<typename T,unsigned int U>
Matrix_r<T,U,U> Matrix_r<T,U,U>::transpose() const{
	Matrix_r<T,U,U> res;
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < U; j++)
			res(j,i) = (*this)(i,j);
	return res;
}

template<typename T,unsigned int U>
Matrix_r<T,U,U> Matrix_r<T,U,U>::invert() const{
	T det = determinant();
	// On vérifie si la matrice est inversible
	if(det == 0.0f)
		return *this;
	Matrix_r<T,U,U> res;
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < U; j++)
			res(j,i) = (((i+j)&1) == 1 ? -1 : 1) * reduce(j,i).determinant();
	return res.transpose() / det;
}

template<typename T,unsigned int U>
Matrix_r<T,U,U> Matrix_r<T,U,U>::normale() const{
	return invert().transpose();
}


template<typename T,unsigned int U>
void Matrix_r<T,U,U>::display(){
	for(unsigned int j = 0; j < U; j++){
		for(unsigned int i = 0; i < U; i++)
			std::cout << (*this)(i,j) << "\t";
		std::cout << std::endl;
	}
}

template<typename T,unsigned int U>
void Matrix_r<T,U,U>::display(const unsigned int x, const unsigned int y){
	std::cout << (*this)(x,y) << std::flush;
}

template<typename T,unsigned int U>
void Matrix_r<T,U,U>::displayColumn(const unsigned int x){
	for(unsigned int i = 0; i < U; i++)
		std::cout << (*this)(x,i) << std::endl;
	std::cout << std::endl;
}

template<typename T,unsigned int U>
void Matrix_r<T,U,U>::displayRow(const unsigned int y){
	for(unsigned int i = 0; i < U; i++)
		std::cout << (*this)(i,y) << "\t";
	std::cout << std::endl;
}

template<unsigned int U, unsigned int V> 
using Matrix = Matrix_r<double,U,V>;
template<unsigned int U, unsigned int V> 
using Matrixf = Matrix_r<float,U,V>;
template<unsigned int U, unsigned int V> 
using Matrixi = Matrix_r<int,U,V>;

typedef Matrix_r<double,2,2> Matrix2x2;
typedef Matrix_r<double,2,3> Matrix2x3;
typedef Matrix_r<double,2,4> Matrix2x4;
typedef Matrix_r<double,3,2> Matrix3x2;
typedef Matrix_r<double,3,3> Matrix3x3;
typedef Matrix_r<double,3,4> Matrix3x4;
typedef Matrix_r<double,4,2> Matrix4x2;
typedef Matrix_r<double,4,3> Matrix4x3;
typedef Matrix_r<double,4,4> Matrix4x4;
typedef Matrix2x2 Matrix2;
typedef Matrix3x3 Matrix3;
typedef Matrix4x4 Matrix4;

typedef Matrix_r<float,2,2> Matrix2x2f;
typedef Matrix_r<float,2,3> Matrix2x3f;
typedef Matrix_r<float,2,4> Matrix2x4f;
typedef Matrix_r<float,3,2> Matrix3x2f;
typedef Matrix_r<float,3,3> Matrix3x3f;
typedef Matrix_r<float,3,4> Matrix3x4f;
typedef Matrix_r<float,4,2> Matrix4x2f;
typedef Matrix_r<float,4,3> Matrix4x3f;
typedef Matrix_r<float,4,4> Matrix4x4f;
typedef Matrix2x2f Matrix2f;
typedef Matrix3x3f Matrix3f;
typedef Matrix4x4f Matrix4f;

typedef Matrix_r<int,2,2> Matrix2x2i;
typedef Matrix_r<int,2,3> Matrix2x3i;
typedef Matrix_r<int,2,4> Matrix2x4i;
typedef Matrix_r<int,3,2> Matrix3x2i;
typedef Matrix_r<int,3,3> Matrix3x3i;
typedef Matrix_r<int,3,4> Matrix3x4i;
typedef Matrix_r<int,4,2> Matrix4x2i;
typedef Matrix_r<int,4,3> Matrix4x3i;
typedef Matrix_r<int,4,4> Matrix4x4i;
typedef Matrix2x2i Matrix2i;
typedef Matrix3x3i Matrix3i;
typedef Matrix4x4i Matrix4i;