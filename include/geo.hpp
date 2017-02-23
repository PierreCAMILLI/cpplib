#pragma once

#include "includes.hpp"
#include "vector.hpp"

#define EPSILON 0.000001

template<typename T>
struct Vector2_t;

template<typename T>
struct Vector3_t;

template<typename T>
struct Point_t;

template<typename T>
struct Line_t
{
	Point_t<T> a, b;

	Line_t(const Point_t<T>& _a = Point_t<T>(), const Point_t<T>& _b = Point_t<T>()) : a(_a), b(_b){}
	Line_t(const Vector3_t<T>& _a = Vector3_t<T>(), const Vector3_t<T>& _b = Vector3_t<T>()) : a(_a), b(_b){}
	Line_t(const Vector3_t<T>& _a = Vector3_t<T>(), const Point_t<T>& _b = Point_t<T>()) : a(_a), b(_b){}
	Line_t(const Point_t<T>& _a = Point_t<T>(), const Vector3_t<T>& _b = Vector3_t<T>()) : a(_a), b(_b){}
	Line_t(const Line_t<T>& l) = default;

	inline T length() const;
	inline T crossProduct(const Point_t<T>& _p) const;

	T distance(const Point_t<T>& _p) const;

	// 2-dimensional
	bool isUpside(const Point_t<T>& _p);
	bool isDownside(const Point_t<T>& _p);
	bool isOn(const Point_t<T>& _p);
	bool areInSameSide(const Point_t<T>& _p1, const Point_t<T>& _p2);

	bool cross(const Line_t<T>& _l, Point_t<T>& _p);
};

template<typename T>
struct Plane_t
{
	Point_t<T> a;
	Vector3_t<T> n;

	Plane_t(const Point_t<T>& _a = Point_t<T>(), const Vector3_t<T>& _n = Vector3_t<T>()) : a(_a), n(_n){}
	Plane_t(const Vector3_t<T>& _a = Vector3_t<T>(), const Vector3_t<T>& _n = Vector3_t<T>()) : a(_a), n(_n){}
	Plane_t(const Plane_t<T>& _p) = default;

	T distance(const Point_t<T>& _p) const;

	bool isAbove(const Point_t<T>& _p);
	bool isBelow(const Point_t<T>& _p);
	bool isIn(const Point_t<T>& _p);
	bool areInSameSide(const Point_t<T>& _p1, const Point_t<T>& _p2);
};

template<typename T>
struct Triangle_t
{
	Point_t<T> a, b, c;

	Triangle_t(const Point_t<T>& _a = Point_t<T>(), const Point_t<T>& _b = Point_t<T>(), const Point_t<T>& _c = Point_t<T>()) : a(_a), b(_b), c(_c){}
	Triangle_t(const Point_t<T>& _a = Point_t<T>(), const Point_t<T>& _b = Point_t<T>(), const Vector3_t<T>& _c = Vector3_t<T>()) : a(_a), b(_b), c(_c){}
	Triangle_t(const Point_t<T>& _a = Point_t<T>(), const Vector3_t<T>& _b = Vector3_t<T>(), const Point_t<T>& _c = Point_t<T>()) : a(_a), b(_b), c(_c){}
	Triangle_t(const Point_t<T>& _a = Point_t<T>(), const Vector3_t<T>& _b = Vector3_t<T>(), const Vector3_t<T>& _c = Vector3_t<T>()) : a(_a), b(_b), c(_c){}
	Triangle_t(const Vector3_t<T>& _a = Vector3_t<T>(), const Point_t<T>& _b = Point_t<T>(), const Point_t<T>& _c = Point_t<T>()) : a(_a), b(_b), c(_c){}
	Triangle_t(const Vector3_t<T>& _a = Vector3_t<T>(), const Point_t<T>& _b = Point_t<T>(), const Vector3_t<T>& _c = Vector3_t<T>()) : a(_a), b(_b), c(_c){}
	Triangle_t(const Vector3_t<T>& _a = Vector3_t<T>(), const Vector3_t<T>& _b = Vector3_t<T>(), const Point_t<T>& _c = Point_t<T>()) : a(_a), b(_b), c(_c){}
	Triangle_t(const Vector3_t<T>& _a = Vector3_t<T>(), const Vector3_t<T>& _b = Vector3_t<T>(), const Vector3_t<T>& _c = Vector3_t<T>()) : a(_a), b(_b), c(_c){}
	Triangle_t(const Triangle_t<T>& _t) = default;

	bool areCollinear();

	T distance(const Point_t<T>& _p) const;

	// 3-dimensional
	Vector3_t<T> normal() const;

	// 2-dimensional
	bool isInside(const Point_t<T>& _p);

	Point_t<T> circumscribedCenter() const;
	Point_t<T> inscribedCenter() const;
};

template<typename T>
struct Circle_t
{
	Point_t<T> c;
	Vector3_t<T> n;
	T r;

	Circle_t(const Point_t<T>& _c = Point_t<T>(), const Vector3_t<T>& _n = Vector3_t<T>(), const T& _r = T()) : c(_c), n(_n), r(_r){}
	Circle_t(const Vector3_t<T>& _c = Point_t<T>(), const Vector3_t<T>& _n = Vector3_t<T>(), const T& _r = T()) : c(_c), n(_n), r(_r){}
	Circle_t(const Circle_t& _c) = default;

	T distance(const Point_t<T>& _p) const;

	// 2-dimensional
	bool isInside(const Point_t<T>& _p);
};

template<typename T>
struct Disc_t
{
	Point_t<T> c;
	Vector3_t<T> n;
	T r;

	Disc_t(const Point_t<T>& _c = Point_t<T>(), const Vector3_t<T>& _n = Vector3_t<T>(), const T& _r = T()) : c(_c), n(_n), r(_r){}
	Disc_t(const Vector3_t<T>& _c = Point_t<T>(), const Vector3_t<T>& _n = Vector3_t<T>(), const T& _r = T()) : c(_c), n(_n), r(_r){}
	Disc_t(const Disc_t& _d) = default;

	T distance(const Point_t<T>& _p) const;

	// 2-dimensional
	bool isInside(const Point_t<T>& _p);
};

template<typename T>
struct Sphere_t
{
	Point_t<T> c;
	T r;

	Sphere_t(const Point_t<T>& _c = Point_t<T>(), const T& _r = T()) : c(_c), r(_r){};
	Sphere_t(const Vector3_t<T>& _c = Vector3_t<T>(), const T& _r = T()) : c(_c), r(_r){};
	Sphere_t(const Sphere_t<T>& _s) = default;

	T distance(const Point_t<T>& _p) const;

	bool isInside(const Point_t<T>& _p);
};

template<typename T>
struct Box_t
{
	Point_t<T> min, max;

	Box_t(const T x1 = T(), const T y1 = T(), const T z1 = T(), const T x2 = T(), const T y2 = T(), const T z2 = T());
	Box_t(const Point_t<T>& _min = Point_t<T>(), const Point_t<T>& _max = Point_t<T>());
	Box_t(const Box_t<T>& _b) = default;

	T distance(const Point_t<T>& _p) const;

	bool isInside(const Point_t<T>& _p);
};

template<typename T>
using VectorPlane_t = std::vector<Plane_t<T>>;
template<typename T>
using VectorTriangle_t = std::vector<Triangle_t<T>>;
template<typename T>
using VectorDisc_t = std::vector<Disc_t<T>>;
template<typename T>
using VectorSphere_t = std::vector<Sphere_t<T>>;
template<typename T>
using VectorBox_t = std::vector<Box_t<T>>;

template<typename T>
struct Geo_Scene_t
{
	VectorPlane_t<T> planes;
	VectorTriangle_t<T> triangles;
	VectorDisc_t<T> discs;
	VectorSphere_t<T> spheres;
	VectorBox_t<T> boxes;

	void operator()(const Plane_t<T> & _p){	planes.push_back(_p);	}
	void operator()(const Triangle_t<T> & _t){	triangles.push_back(_t);	}
	void operator()(const Disc_t<T> & _d){	discs.push_back(_d);	}
	void operator()(const Sphere_t<T> & _s){	spheres.push_back(_s);	}
	void operator()(const Box_t<T> & _b){	boxes.push_back(_b);	}

	Geo_Scene_t<T>& operator<<(const Plane_t<T> & _p){	planes.push_back(_p);	return *this;	}
	Geo_Scene_t<T>& operator<<(const Triangle_t<T> & _t){	triangles.push_back(_t);	return *this;	}
	Geo_Scene_t<T>& operator<<(const Disc_t<T> & _d){	discs.push_back(_d);	return *this;	}
	Geo_Scene_t<T>& operator<<(const Sphere_t<T> & _s){	spheres.push_back(_s);	return *this;	}
	Geo_Scene_t<T>& operator<<(const Box_t<T> & _b){	boxes.push_back(_b);	return *this;	}

	int size(){	return 		planes.size()
						+	triangles.size()
						+	discs.size()
						+	spheres.size()
						+	boxes.size();}
};

template<typename T>
struct Hit_t
{
	Point_t<T> p;
	Vector3_t<T> n;
	T d;

	Hit_t(const Point_t<T>& _p = Point_t<T>(), const Vector3_t<T>& _n = Vector3_t<T>(), const T& _d = infinity()) : p(_p), n(_n), d(_d){}

	static T infinity() {	return std::numeric_limits<T>::infinity();	}
};

template<typename T>
using VectorHit_t = std::vector<Hit_t<T>>;

template<typename T>
struct Ray_t
{
	Point_t<T> o;
	Vector3_t<T> d;

	Ray_t(const Point_t<T>& _o = Point_t<T>(), const Vector3_t<T>& _d = Vector3_t<T>()) : o(_o), d(_d){};
	Ray_t(const Vector3_t<T>& _o = Vector3_t<T>(), const Vector3_t<T>& _d = Vector3_t<T>()) : o(_o), d(_d){};
	Ray_t(const Ray_t<T>& r) = default;

	static void orderHits(VectorHit_t<T>& hits);

	// intersections
	// collision unitaire
	bool operator()(const Plane_t<T>& _p, Hit_t<T>& _h);
	bool operator()(const Triangle_t<T>& _t, Hit_t<T>& _h);
	bool operator()(const Disc_t<T>& _d, Hit_t<T>& _h);
	bool operator()(const Sphere_t<T>& _s, Hit_t<T>& _h);
	bool operator()(const Box_t<T>& _b, Hit_t<T>& _h);

	// première collision
	bool operator()(const VectorPlane_t<T>& _p, Hit_t<T>& _h);
	bool operator()(const VectorTriangle_t<T>& _t, Hit_t<T>& _h);
	bool operator()(const VectorDisc_t<T>& _d, Hit_t<T>& _h);
	bool operator()(const VectorSphere_t<T>& _s, Hit_t<T>& _h);
	bool operator()(const VectorBox_t<T>& _b, Hit_t<T>& _h);

	bool operator()(const Geo_Scene_t<T>& _sc, Hit_t<T>& _h);

	// vecteur de collisions, classé du premier au dernier touché
	VectorHit_t<T> operator()(const VectorPlane_t<T>& _p);
	VectorHit_t<T> operator()(const VectorTriangle_t<T>& _t);
	VectorHit_t<T> operator()(const VectorDisc_t<T>& _d);
	VectorHit_t<T> operator()(const VectorSphere_t<T>& _s);
	VectorHit_t<T> operator()(const VectorBox_t<T>& _b);

	VectorHit_t<T> operator()(const Geo_Scene_t<T>& _sc);
};

typedef Line_t<double> Line;
typedef Line_t<float> Linef;
typedef Line_t<int> Linei;

typedef Triangle_t<double> Triangle;
typedef Triangle_t<float> Trianglef;
typedef Triangle_t<int> Trianglei;

typedef Circle_t<double> Circle;
typedef Circle_t<float> Circlef;
typedef Circle_t<int> Circlei;

typedef Disc_t<double> Disc;
typedef Disc_t<float> Discf;
typedef Disc_t<int> Disci;

typedef Sphere_t<double> Sphere;
typedef Sphere_t<float> Spheref;
typedef Sphere_t<int> Spherei;

typedef Box_t<double> Box;
typedef Box_t<float> Boxf;
typedef Box_t<int> Boxi;

typedef Plane_t<double> Plane;
typedef Plane_t<float> Planef;
typedef Plane_t<int> Planei;

typedef Geo_Scene_t<double> Geo_Scene;
typedef Geo_Scene_t<float> Geo_Scenef;
typedef Geo_Scene_t<int> Geo_Scenei;

typedef Hit_t<double> Hit;
typedef Hit_t<float> Hitf;
typedef Hit_t<int> Hiti;

typedef Ray_t<double> Ray;
typedef Ray_t<float> Rayf;
typedef Ray_t<int> Rayi;