#pragma once

#include "includes.hpp"

template<typename T>
struct Vector2_t;

template<typename T>
struct Raycast2D_t;

template<typename T>
struct RaycastHit2D_t;

template<typename T>
class Shape2D_t{
	private:

	public:
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
		
		T Length() const;
		bool IsUpside(const Vector2_t<T> & point);
		bool Cross(const Line_t<T>& line, Vector2_t<T>& point);
		Vector2_t<T> Projection(const Vector2_t<T>& point) const;

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
		
		void Translate(const Vector2_t<T>& translation);
		void Resize(const Vector2_t<T>& size);
		T Distance(const Vector2_t<T>& point) const;
		void Bounds(Vector2_t<T>& min, Vector2_t<T>& max);
		bool operator()(const Raycast2D_t<T> & ray, RaycastHit2D_t<T>& hit);
};

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

		bool IsInside(const Vector2_t<T>& point);

		void Translate(const Vector2_t<T>& translation);
		void Resize(const Vector2_t<T>& size);
		T Distance(const Vector2_t<T>& point) const;
		void Bounds(Vector2_t<T>& min, Vector2_t<T>& max);
		bool operator()(const Raycast2D_t<T> & ray, RaycastHit2D_t<T>& hit);
};

template<typename T>
class Polygon2D_t : public Shape2D_t<T>
{
	private:
	public:
		Polygon2D_t();
		Polygon2D_t(const Polygon2D_t<T>& p) = default;

		void Translate(const Vector2_t<T>& translation);
		void Resize(const Vector2_t<T>& size);
		T Distance(const Vector2_t<T>& point) const;
		void Bounds(Vector2_t<T>& min, Vector2_t<T>& max);
		bool operator()(const Raycast2D_t<T> & ray, RaycastHit2D_t<T>& hit);
	
};