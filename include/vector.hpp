#pragma once

#include "includes.hpp"

template<typename T>
struct Vector3_t;

template<typename T>
struct Point_t;

template<typename T>
struct Vector4_t;

template<typename T>
struct Vector2_t
{
	T x, y;

	Vector2_t(const T _x = T(), const T _y = T()) : x(_x), y(_y){}
	Vector2_t(const Vector2_t<T>& v) = default;
	explicit Vector2_t(const Vector3_t<T>& v) : x(v.x), y(v.y){};
	explicit Vector2_t(const Point_t<T>& p) : x(p.x), y(p.y){};
	explicit Vector2_t(const Vector4_t<T>& v) : x(v.x), y(v.y){};

	template<typename TT>
	friend std::ostream& operator<<(std::ostream& o, const Vector2_t<TT>& _v);

	Vector2_t<T>& operator()(const T _x = T(), const T _y = T());
	Vector2_t<T> operator+(const Vector2_t<T>& _v) const;
	Vector2_t<T> operator+(const T& n) const;
	Vector2_t<T> operator-() const;
	Vector2_t<T> operator-(const Vector2_t<T>& _v) const;
	Vector2_t<T> operator-(const T& n) const;
	Vector2_t<T> operator*(const Vector2_t<T>& _v) const;
	Vector2_t<T> operator*(const T& n) const;
	Vector2_t<T> operator/(const T& n) const;
	bool operator==(const Vector2_t<T>& _v);
	bool operator!=(const Vector2_t<T>& _v);
	T operator[](const unsigned int& i) const;
	T& operator[](const unsigned int& i);

	T length() const;
	T dot(const Vector2_t<T>& _v) const;
	Vector2_t<T> normalize() const;

	void display();
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vector2_t<T>& _v){
	o << "v(" << _v.x << "," << _v.y << ")";
	return o;
}

template<typename T>
struct Vector3_t
{
	T x, y, z;

	Vector3_t(const T _x = T(), const T _y = T(), const T _z = T()) : x(_x), y(_y), z(_z){}
	Vector3_t(const Vector3_t<T>& v) = default;
	explicit Vector3_t(const Vector2_t<T>& v, const T _z = T()) : x(v.x), y(v.y), z(_z){};
	explicit Vector3_t(const T _x, const Vector2_t<T>& v) : x(_x), y(v.x), z(v.y){};
	explicit Vector3_t(const Point_t<T>& p) : x(p.x), y(p.y), z(p.z){}
	explicit Vector3_t(const Vector4_t<T>& v) : x(v.x), y(v.y), z(v.z){};

	template<typename TT>
	friend std::ostream& operator<<(std::ostream& o, const Vector3_t<TT>& _v);

	Vector3_t<T>& operator()(const T _x = T(), const T _y = T(), const T _z = T());
	Vector3_t<T> operator+(const Vector3_t<T>& _v) const;
	Vector3_t<T> operator+(const T& n) const;
	Vector3_t<T> operator-() const;
	Vector3_t<T> operator-(const Vector3_t<T>& _v) const;
	Vector3_t<T> operator-(const T& n) const;
	Vector3_t<T> operator*(const Vector3_t<T>& _v) const;
	Vector3_t<T> operator*(const T& n) const;
	Vector3_t<T> operator/(const T& n) const;
	bool operator==(const Vector3_t<T>& _v);
	bool operator!=(const Vector3_t<T>& _v);
	T operator[](const unsigned int& i) const;
	T& operator[](const unsigned int& i);

	T length() const;
	T dot(const Vector3_t<T>& _v) const;
	Vector3_t<T> cross(const Vector3_t<T>& _v) const;
	Vector3_t<T> normalize() const;

	void display();
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vector3_t<T>& _v){
	o << "v(" << _v.x << "," << _v.y << "," << _v.z << ")";
	return o;
}

template<typename T>
struct Point_t
{
	T x, y, z;

	Point_t(const T _x = T(), const T _y = T(), const T _z = T()) : x(_x), y(_y), z(_z){}
	Point_t(const Point_t<T>& _p) = default;
	explicit Point_t(const Vector2_t<T>& v, const T _z = T()) : x(v.x), y(v.y), z(_z){};
	explicit Point_t(const T _x, const Vector2_t<T>& v) : x(_x), y(v.x), z(v.y){};
	explicit Point_t(const Vector3_t<T>& v) : x(v.x), y(v.y), z(v.z){};
	explicit Point_t(const Vector4_t<T>& v) : x(v.x), y(v.y), z(v.z){};

	template<typename TT>
	friend std::ostream& operator<<(std::ostream& o, const Point_t<TT>& _p);

	Vector3_t<T> operator-(const Point_t<T>& _p) const;
	Point_t<T>& operator()(const T _x = T(), const T _y = T(), const T _z = T());
	Point_t<T> operator+(const Vector3_t<T>& _v) const;
	Point_t<T> operator+(const T& n) const;
	Point_t<T> operator-() const;
	Point_t<T> operator-(const Vector3_t<T>& _v) const;
	Point_t<T> operator-(const T& n) const;
	Point_t<T> operator*(const Vector3_t<T>& _v) const;
	Point_t<T> operator*(const T& n) const;
	Point_t<T> operator/(const T& n) const;
	bool operator==(const Point_t<T>& _v);
	bool operator!=(const Point_t<T>& _v);
	T operator[](const unsigned int& i) const;
	T& operator[](const unsigned int& i);

	T distance(const Point_t<T>& _p) const;
	Point_t<T> center(const Point_t<T>& _p) const;

	void display();
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const Point_t<T>& _p){
	o << "p(" << _p.x << "," << _p.y << "," << _p.z << ")";
	return o;
}

template<typename T>
struct Vector4_t
{
	T x, y, z, w;

	Vector4_t(const T _x = T(), const T _y = T(), const T _z = T(), const T _w = T()) : x(_x), y(_y), z(_z), w(_w){}
	Vector4_t(const Vector4_t<T>& v) = default;
	explicit Vector4_t(const Vector2_t<T>& v, const T _z = T(), const T _w = T()) : x(v.x), y(v.y), z(_z), w(_w){};
	explicit Vector4_t(const T _x, const Vector2_t<T>& v, const T _w = T()) : x(_x), y(v.x), z(v.y), w(_w){};
	explicit Vector4_t(const T _x, const T _y, const Vector2_t<T>& v) : x(_x), y(_y), z(v.x), w(v.y){};
	explicit Vector4_t(const Vector2_t<T>& v1, const Vector2_t<T>& v2) : x(v1.x), y(v1.y), z(v2.x), w(v2.y){};
	explicit Vector4_t(const Vector3_t<T>& v, const T _w = T()) : x(v.x), y(v.y), z(v.z), w(_w){};
	explicit Vector4_t(const T _x, const Vector3_t<T>& v) : x(_x), y(v.x), z(v.y), w(v.z){};
	explicit Vector4_t(const Point_t<T>& p) : x(p.x), y(p.y), z(p.z), w(T()){}
	explicit Vector4_t(const Point_t<T>& p, const T _w = T()) : x(p.x), y(p.y), z(p.z), w(_w){};
	explicit Vector4_t(const T _x, const Point_t<T>& p) : x(_x), y(p.x), z(p.y), w(p.z){};

	template<typename TT>
	friend std::ostream& operator<<(std::ostream& o, const Vector4_t<TT>& _v);

	Vector4_t<T>& operator()(const T _x = T(), const T _y = T(), const T _z = T(), const T _w = T());
	Vector4_t<T> operator+(const Vector4_t<T>& _v) const;
	Vector4_t<T> operator+(const T& n) const;
	Vector4_t<T> operator-() const;
	Vector4_t<T> operator-(const Vector4_t<T>& _v) const;
	Vector4_t<T> operator-(const T& n) const;
	Vector4_t<T> operator*(const Vector4_t<T>& _v) const;
	Vector4_t<T> operator*(const T& n) const;
	Vector4_t<T> operator/(const T& n) const;
	bool operator==(const Vector4_t<T>& _v);
	bool operator!=(const Vector4_t<T>& _v);
	T operator[](const unsigned int& i) const;
	T& operator[](const unsigned int& i);

	T length() const;
	T dot(const Vector3_t<T>& _v) const;
	Vector4_t<T> normalize() const;

	void display();
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vector4_t<T>& _v){
	o << "v(" << _v.x << "," << _v.y << "," << _v.z << "," << _v.w << ")";
	return o;
}

typedef Vector2_t<double> Vector2;
typedef Vector2_t<float> Vector2f;
typedef Vector2_t<int> Vector2i;

typedef Vector3_t<double> Vector3;
typedef Vector3_t<float> Vector3f;
typedef Vector3_t<int> Vector3i;

typedef Point_t<double> Point;
typedef Point_t<float> Pointf;
typedef Point_t<int> Pointi;

typedef Vector4_t<double> Vector4;
typedef Vector4_t<float> Vector4f;
typedef Vector4_t<int> Vector4i;