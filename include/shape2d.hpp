#pragma once

#include "ray.hpp"
#include "triangulation.hpp"

#define SHAPE_PI 3.14159265359

template<typename T>
struct Raycast2D_t;

template<typename T>
struct RaycastHit2D_t;

template<typename T>
class Shape2D_t{
	private:

	public:
		virtual RaycastHit2D_t<T> operator()(const Raycast2D_t<T>& ray){	RaycastHit2D_t<T> hit;	(*this)(ray, hit);	return hit;	};

		virtual bool Contains(const Vector2_t<T>& point) const = 0;
		virtual void Translate(const Vector2_t<T>& translation) = 0;
		virtual void Resize(const Vector2_t<T>& size) = 0;
		virtual T Distance(const Vector2_t<T>& point) const = 0;
		virtual void Bounds(Vector2_t<T>& min, Vector2_t<T>& max) = 0;
		virtual bool operator()(const Raycast2D_t<T>& ray, RaycastHit2D_t<T>& hit) = 0;
};

template<typename T>
class Line_t : public Shape2D_t<T>{
	private:
		Vector2_t<T> a, b;
	public:
		Line_t<T>(const Line_t<T> & l) = default;
		Line_t<T>(const Vector2_t<T>& _a = Vector2_t<T>(), const Vector2_t<T>& _b = Vector2_t<T>()) : a(_a), b(_b){}
		
		Vector2_t<T> Vector() const;
		T Length() const;
		bool IsUpside(const Vector2_t<T> & point) const;
		bool AreInSameSide(const Vector2_t<T> & p1, const Vector2_t<T> & p2) const;
		bool Cross(const Line_t<T>& line, Vector2_t<T>& point) const;
		Vector2_t<T> Projection(const Vector2_t<T>& point) const;

		static bool Cross(const Line_t<T>& line1, const Line_t<T>& line2, Vector2_t<T>& point){	return line1.Cross(line2,point);	}

		RaycastHit2D_t<T> operator()(const Raycast2D_t<T>& ray) {	return Shape2D_t<T>::operator()(ray);	};

		bool Contains(const Vector2_t<T>& point) const;
		void Translate(const Vector2_t<T>& translation);
		void Resize(const Vector2_t<T>& size);
		T Distance(const Vector2_t<T>& point) const;
		void Bounds(Vector2_t<T>& min, Vector2_t<T>& max);
		bool operator()(const Raycast2D_t<T>& ray, RaycastHit2D_t<T>& hit);
};

typedef Line_t<double> Line;
typedef Line_t<float> Linef;
typedef Line_t<int> Linei;

template<typename T>
class Circle_t : public Shape2D_t<T>{
	private:
		Vector2_t<T> center;
		T radius;
	public:
		Circle_t<T>(const Circle_t<T> & c) = default;
		Circle_t<T>(const Vector2_t<T>& _center = Vector2_t<T>(), const T & _radius = T()) : center(_center), radius(_radius){}
		
		T Area() const;

		RaycastHit2D_t<T> operator()(const Raycast2D_t<T>& ray) {	return Shape2D_t<T>::operator()(ray);	};

		bool Contains(const Vector2_t<T>& point) const;
		void Translate(const Vector2_t<T>& translation);
		void Resize(const Vector2_t<T>& size);
		T Distance(const Vector2_t<T>& point) const;
		void Bounds(Vector2_t<T>& min, Vector2_t<T>& max);
		bool operator()(const Raycast2D_t<T> & ray, RaycastHit2D_t<T>& hit);
};

typedef Circle_t<double> Circle;
typedef Circle_t<float> Circlef;
typedef Circle_t<int> Circlei;

template<typename T>
class Triangle2D_t : public Shape2D_t<T>{
	private:
		Vector2_t<T> a, b, c;
	public:
		Triangle2D_t<T>(const Triangle2D_t<T> & t) = default;
		Triangle2D_t<T>(
			const Vector2_t<T>& _a = Vector2_t<T>(),
			const Vector2_t<T>& _b = Vector2_t<T>(),
			const Vector2_t<T>& _c = Vector2_t<T>()) : a(_a), b(_b), c(_c){}

		Vector2_t<T> Circumcenter() const;
		Vector2_t<T> Incenter() const;
		Vector2_t<T> Centroid() const;
		T Area() const;
		T AspectRatio() const;

		RaycastHit2D_t<T> operator()(const Raycast2D_t<T>& ray) {	return Shape2D_t<T>::operator()(ray);	};

		bool Contains(const Vector2_t<T>& point) const;
		void Translate(const Vector2_t<T>& translation);
		void Resize(const Vector2_t<T>& size);
		T Distance(const Vector2_t<T>& point) const;
		void Bounds(Vector2_t<T>& min, Vector2_t<T>& max);
		bool operator()(const Raycast2D_t<T> & ray, RaycastHit2D_t<T>& hit);
};

typedef Triangle2D_t<double> Triangle2D;
typedef Triangle2D_t<float> Triangle2Df;
typedef Triangle2D_t<int> Triangle2Di;

template<typename T>
class Polygon2D : public Shape2D_t<double>
{
	private:
		Triangulation * const triangulation;
	public:
		Polygon2D(const Polygon2D& p) = default;
		Polygon2D(Triangulation& _triangulation) : triangulation(&_triangulation){}

		bool Contains(const Vector2_t<double>& point) const;
		void Translate(const Vector2_t<double>& translation);
		void Resize(const Vector2_t<double>& size);
		double Distance(const Vector2_t<double>& point) const;
		void Bounds(Vector2_t<double>& min, Vector2_t<double>& max);
		bool operator()(const Raycast2D_t<double> & ray, RaycastHit2D_t<double>& hit);
	
};