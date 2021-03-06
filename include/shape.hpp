#pragma once

#include "ray.hpp"
#include "mesh.hpp"

template<typename T>
struct Raycast_t;

template<typename T>
struct RaycastHit_t;

template<typename T>
class Shape_t{
	public:
		virtual RaycastHit_t<T> operator()(const Raycast_t<T>& ray){	RaycastHit_t<T> hit;	(*this)(ray, hit);	return hit;	};

		virtual bool Contains(const Vector3_t<T>& point) = 0;
		virtual void Translate(const Vector3_t<T>& translation) = 0;
		virtual void Resize(const Vector3_t<T>& size) = 0;
		virtual T Distance(const Vector3_t<T>& point) const = 0;
		virtual void Bounds(Vector3_t<T>& min, Vector3_t<T>& max) = 0;
		virtual bool operator()(const Raycast_t<T> & ray, RaycastHit_t<T>& hit) = 0;
};

template<typename T>
class Plane_t{
	private:
		Vector3_t<T> origin;
		Vector3_t<T> normal;
	public:
		Plane_t(const Plane_t<T>& p) = default;
		Plane_t(const Vector3_t<T>& _origin, const Vector3_t<T> & _normal) : origin(_origin), normal(_normal){}

		// RaycastHit_t<T> operator()(const Raycast_t<T>& ray) {	return Shape_t<T>::operator()(ray);	};

		Vector3_t<T> Projection(const Vector3_t<T>& point);

		bool Contains(const Vector3_t<T>& point);
		void Translate(const Vector3_t<T>& translation);
		void Resize(const Vector3_t<T>& size);
		T Distance(const Vector3_t<T>& point) const;
		void Bounds(Vector3_t<T>& min, Vector3_t<T>& max);
		bool operator()(const Raycast_t<T> & ray, RaycastHit_t<T>& hit);
};

typedef Plane_t<double> Plane;
typedef Plane_t<float> Planef;
typedef Plane_t<int> Planei;

template<typename T>
class Sphere_t : public Shape_t<T>
{
	private:
		Vector3_t<T> center;
		T radius;
	public:
		Sphere_t(const Sphere_t<T>& s) = default;
		Sphere_t(const Vector3_t<T>& _center, const T & _radius) : center(_center), radius(_radius){}

		RaycastHit_t<T> operator()(const Raycast_t<T>& ray) {	return Shape_t<T>::operator()(ray);	};

		bool Contains(const Vector3_t<T>& point);
		void Translate(const Vector3_t<T>& translation);
		void Resize(const Vector3_t<T>& size);
		T Distance(const Vector3_t<T>& point) const;
		void Bounds(Vector3_t<T>& min, Vector3_t<T>& max);
		bool operator()(const Raycast_t<T> & ray, RaycastHit_t<T>& hit);
};

typedef Sphere_t<double> Sphere;
typedef Sphere_t<float> Spheref;
typedef Sphere_t<int> Spherei;

template<typename T>
class Triangle_t : public Shape_t<T>
{
	private:
		Vector3_t<T> a, b, c;
	public:
		Triangle_t<T>(const Triangle_t<T>& t) = default;
		Triangle_t<T>(
			const Vector3_t<T>& _a = Vector3_t<T>(),
			const Vector3_t<T>& _b = Vector3_t<T>(),
			const Vector3_t<T>& _c = Vector3_t<T>()) : a(_a), b(_b), c(_c){}

		Vector3_t<T> Normal() const{	return Vector3_t<T>::Cross(a - b, a - c);	}

		RaycastHit_t<T> operator()(const Raycast_t<T>& ray) {	return Shape_t<T>::operator()(ray);	};

		bool Contains(const Vector3_t<T>& point);
		void Translate(const Vector3_t<T>& translation);
		void Resize(const Vector3_t<T>& size);
		T Distance(const Vector3_t<T>& point) const;
		void Bounds(Vector3_t<T>& min, Vector3_t<T>& max);
		bool operator()(const Raycast_t<T> & ray, RaycastHit_t<T>& hit);	
};

typedef Triangle_t<double> Triangle;
typedef Triangle_t<float> Trianglef;
typedef Triangle_t<int> Trianglei;

template<typename T>
class Box_t : public Shape_t<T>
{
	private:
		Vector3_t<T> min, max;
	public:
		Box_t<T>(const Box_t<T>& t) = default;
		Box_t<T>(
			const Vector3_t<T>& _min = Vector3_t<T>(),
			const Vector3_t<T>& _max = Vector3_t<T>()) : min(_min), max(_max){}

		RaycastHit_t<T> operator()(const Raycast_t<T>& ray) {	return Shape_t<T>::operator()(ray);	};

		bool Contains(const Vector3_t<T>& point);
		void Translate(const Vector3_t<T>& translation);
		void Resize(const Vector3_t<T>& size);
		T Distance(const Vector3_t<T>& point) const;
		void Bounds(Vector3_t<T>& min, Vector3_t<T>& max);
		bool operator()(const Raycast_t<T> & ray, RaycastHit_t<T>& hit);	
};

class MeshShape : public Shape_t<double>
{
	private:
		Mesh * const m;
	public:
		MeshShape(const MeshShape& ms) = default;
		MeshShape(Mesh& _m) : m(&_m){} 

		RaycastHit_t<double> operator()(const Raycast_t<double>& ray) {	return Shape_t<double>::operator()(ray);	};

		bool Contains(const Vector3_t<double>& point);
		void Translate(const Vector3_t<double>& translation);
		void Resize(const Vector3_t<double>& size);
		double Distance(const Vector3_t<double>& point) const;
		void Bounds(Vector3_t<double>& min, Vector3_t<double>& max);
		bool operator()(const Raycast_t<double> & ray, RaycastHit_t<double>& hit);	
	
};