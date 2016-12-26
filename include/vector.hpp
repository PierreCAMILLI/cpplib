#pragma once

#include "includes.hpp"

template<typename T>
struct Vector3_t;

template<typename T>
struct Point_t;

template<typename T>
struct Vector2_t
{
	T x, y;

	Vector2_t(const T _x = T(), const T _y = T()) : x(_x), y(_y){}
	Vector2_t(const Vector2_t<T>& v) = default;
	explicit Vector2_t(const Vector3_t<T>& v) : x(v.x), y(v.y){};
	explicit Vector2_t(const Point_t<T>& p) : x(p.x), y(p.y){};

	Vector2_t<T> operator()(const T _x = T(), const T _y = T());
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
struct Vector3_t
{
	T x, y, z;

	Vector3_t(const T _x = T(), const T _y = T(), const T _z = T()) : x(_x), y(_y), z(_z){}
	Vector3_t(const Vector3_t<T>& v) = default;
	explicit Vector3_t(const Vector2_t<T>& v) : x(v.x), y(v.y), z(T()){};
	explicit Vector3_t(const Point_t<T>& p) : x(p.x), y(p.y), z(p.z){}

	Vector3_t<T> operator()(const T _x = T(), const T _y = T(), const T _z = T());
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
	Vector3_t<T> normalize() const;

	void display();
};

template<typename T>
struct Point_t
{
	T x, y, z;

	Point_t(const T _x = T(), const T _y = T(), const T _z = T()) : x(_x), y(_y), z(_z){}
	Point_t(const Point_t<T>& _p) = default;
	explicit Point_t(const Vector2_t<T>& v) : x(v.x), y(v.y), z(T()){};
	explicit Point_t(const Vector3_t<T>& v) : x(v.x), y(v.y), z(v.z){};

	Vector3_t<T> operator-(const Point_t<T>& _p) const;
	Point_t<T> operator()(const T _x = T(), const T _y = T(), const T _z = T());
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

typedef Vector2_t<double> Vector2;
typedef Vector2_t<float> Vector2f;
typedef Vector2_t<int> Vector2i;

typedef Vector3_t<double> Vector3;
typedef Vector3_t<float> Vector3f;
typedef Vector3_t<int> Vector3i;

typedef Point_t<double> Point;
typedef Point_t<float> Pointf;
typedef Point_t<int> Pointi;