#pragma once

#include "includes.hpp"

#define CURVE_PI 3.14159265359

template<typename T>
struct Vector2_t;

template<typename T>
using VectorControl_t = std::vector<Vector2_t<T> >;

template<typename T>
class Curve_t{
	private:
		
		VectorControl_t<T> controls;
		
		void sort();
		unsigned int getIndexOf(const T& _x);

	public:
		T default_value = T();

		Curve_t<T>() = default;
		Curve_t<T>(Vector2_t<T>* a_con, unsigned int size);
		Curve_t<T>(const VectorControl_t<T>& v_c) : controls(v_c){	sort();	}
		void release();

		T const operator()(const T& _x){	return Sine(_x);	}
		T const & operator[] (const unsigned int& i) const{	return controls[i].y;	}
		T& operator[](const unsigned int& i){	return controls[i].y;	}

		Curve_t<T> point(const T& _x, const T& _y);
		Curve_t<T> point(const Vector2_t<T>& _v);
		bool contains(const T& _x);
		bool contains(const T& _x, const T& _y);
		bool move(const unsigned int& i, const unsigned int& _x);
		bool remove(const unsigned int& i);
		size_t const size() const{	return controls.size();	}

		T const Linear(const T& _x);
		T const Sine(const T& _x);
		T const Quad(const T& _x);

		Curve_t<T> const Bezier(const unsigned int& coeff = 2);
};

typedef Curve_t<double> Curve;
typedef Curve_t<float> Curvef;
typedef Curve_t<int> Curvei;