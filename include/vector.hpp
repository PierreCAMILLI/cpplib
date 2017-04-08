#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <cmath>
#include <iostream>

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
	Vector2_t(const Vector3_t<T>& v) : x(v.x), y(v.y){};
	Vector2_t(const Point_t<T>& p) : x(p.x), y(p.y){};
	Vector2_t(const Vector4_t<T>& v) : x(v.x), y(v.y){};

	template<typename TT>
	friend std::ostream& operator<<(std::ostream& o, const Vector2_t<TT>& _v);

	Vector2_t<T>& operator()(const T _x = T(), const T _y = T());
	Vector2_t<T>& operator+=(const Vector2_t<T>& _v);
	Vector2_t<T>& operator+=(const T& n);
	Vector2_t<T>& operator-=(const Vector2_t<T>& _v);
	Vector2_t<T>& operator-=(const T& n);
	Vector2_t<T>& operator*=(const Vector2_t<T>& _v);
	Vector2_t<T>& operator*=(const T& n);
	Vector2_t<T>& operator/=(const T& n);

	Vector2_t<T> operator+(const Vector2_t<T>& _v) const{	return Vector2_t<T>(*this) += _v;	};
	Vector2_t<T> operator+(const T& n) const{	return Vector2_t<T>(*this) += n;	};
	Vector2_t<T> operator-() const{	return (*this) * T(-1);	};
	Vector2_t<T> operator-(const Vector2_t<T>& _v) const{	return Vector2_t<T>(*this) -= _v;	};
	Vector2_t<T> operator-(const T& n) const{	return Vector2_t<T>(*this) -= n;	};
	Vector2_t<T> operator*(const Vector2_t<T>& _v) const{	return Vector2_t<T>(*this) *= _v;	};
	Vector2_t<T> operator*(const T& n) const{	return Vector2_t<T>(*this) *= n;	};
	Vector2_t<T> operator/(const T& n) const{	return Vector2_t<T>(*this) /= n;	};

	bool operator==(const Vector2_t<T>& _v);
	bool operator!=(const Vector2_t<T>& _v);
	T operator[](const unsigned int& i) const;
	T& operator[](const unsigned int& i);

	T SquaredLength() const;
	T Length() const;
	T Dot(const Vector2_t<T>& _v) const;
	Vector2_t<T>& Normalize();
	Vector2_t<T> Normalized() const{	return Vector2_t<T>(*this).Normalize();	};

	void Display();

	static T const Dot(const Vector2_t<T>& _v1, const Vector2_t<T>& _v2){	return _v1.Dot(_v2);	}
	static T const SquaredDistance(const Vector2_t<T>& _v1, const Vector2_t<T>& _v2){	return (_v1 - _v2).SquaredLength();	}
	static T const Distance(const Vector2_t<T>& _v1, const Vector2_t<T>& _v2){	return (_v1 - _v2).Length();	}
	static Vector2_t<T> const Middle(const Vector2_t<T>& _v1, const Vector2_t<T>& _v2){	return (_v1 + _v2) / T(2);	}
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vector2_t<T>& _v){
	return o << "v(" << _v.x << "," << _v.y << ")";
}

template<typename T>
struct Vector3_t
{
	T x, y, z;

	Vector3_t(const T _x = T(), const T _y = T(), const T _z = T()) : x(_x), y(_y), z(_z){}
	Vector3_t(const Vector3_t<T>& v) = default;
	Vector3_t(const Vector2_t<T>& v) : x(v.x), y(v.y), z(T()){};
	explicit Vector3_t(const Vector2_t<T>& v, const T _z = T()) : x(v.x), y(v.y), z(_z){};
	explicit Vector3_t(const T _x, const Vector2_t<T>& v) : x(_x), y(v.x), z(v.y){};
	Vector3_t(const Point_t<T>& p) : x(p.x), y(p.y), z(p.z){}
	Vector3_t(const Vector4_t<T>& v) : x(v.x), y(v.y), z(v.z){};

	template<typename TT>
	friend std::ostream& operator<<(std::ostream& o, const Vector3_t<TT>& _v);

	Vector3_t<T>& operator()(const T _x = T(), const T _y = T(), const T _z = T());
	Vector3_t<T>& operator+=(const Vector3_t<T>& _v);
	Vector3_t<T>& operator+=(const T& n);
	Vector3_t<T>& operator-=(const Vector3_t<T>& _v);
	Vector3_t<T>& operator-=(const T& n);
	Vector3_t<T>& operator*=(const Vector3_t<T>& _v);
	Vector3_t<T>& operator*=(const T& n);
	Vector3_t<T>& operator/=(const T& n);

	Vector3_t<T> operator+(const Vector3_t<T>& _v) const{	return Vector3_t<T>(*this) += _v;	};
	Vector3_t<T> operator+(const T& n) const{	return Vector3_t<T>(*this) += n;	};
	Vector3_t<T> operator-() const{	return (*this) * T(-1);	};
	Vector3_t<T> operator-(const Vector3_t<T>& _v) const{	return Vector3_t<T>(*this) -= _v;	};
	Vector3_t<T> operator-(const T& n) const{	return Vector3_t<T>(*this) -= n;	};
	Vector3_t<T> operator*(const Vector3_t<T>& _v) const{	return Vector3_t<T>(*this) *= _v;	};
	Vector3_t<T> operator*(const T& n) const{	return Vector3_t<T>(*this) *= n;	};
	Vector3_t<T> operator/(const T& n) const{	return Vector3_t<T>(*this) *= n;	};
	bool operator==(const Vector3_t<T>& _v);
	bool operator!=(const Vector3_t<T>& _v);
	T operator[](const unsigned int& i) const;
	T& operator[](const unsigned int& i);

	T SquaredLength() const;
	T Length() const;
	T Dot(const Vector3_t<T>& _v) const;
	Vector3_t<T> Cross(const Vector3_t<T>& _v) const;
	Vector3_t<T>& Normalize();
	Vector3_t<T> Normalized() const{	return Vector3_t<T>(*this).Normalize();	};

	void Display();

	static T const Dot(const Vector3_t<T>& _v1, const Vector3_t<T>& _v2){	return _v1.Dot(_v2);	}
	static Vector3_t<T> const Cross(const Vector3_t<T>& _v1, const Vector3_t<T>& _v2){	return _v1.Cross(_v2);	}
	static T const SquaredDistance(const Vector3_t<T>& _v1, const Vector3_t<T>& _v2){	return (_v1 - _v2).SquaredLength();	}
	static T const Distance(const Vector3_t<T>& _v1, const Vector3_t<T>& _v2){	return (_v1 - _v2).Length();	}
	static Vector3_t<T> const Middle(const Vector3_t<T>& _v1, const Vector3_t<T>& _v2){	return (_v1 + _v2) / T(2);	}
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vector3_t<T>& _v){
	return o << "v(" << _v.x << "," << _v.y << "," << _v.z << ")";
}

template<typename T>
struct Point_t
{
	T x, y, z;

	Point_t(const T _x = T(), const T _y = T(), const T _z = T()) : x(_x), y(_y), z(_z){}
	Point_t(const Point_t<T>& _p) = default;
	Point_t(const Vector2_t<T>& v) : x(v.x), y(v.y), z(T()){};
	explicit Point_t(const Vector2_t<T>& v, const T _z = T()) : x(v.x), y(v.y), z(_z){};
	explicit Point_t(const T _x, const Vector2_t<T>& v) : x(_x), y(v.x), z(v.y){};
	Point_t(const Vector3_t<T>& v) : x(v.x), y(v.y), z(v.z){};
	Point_t(const Vector4_t<T>& v) : x(v.x), y(v.y), z(v.z){};

	template<typename TT>
	friend std::ostream& operator<<(std::ostream& o, const Point_t<TT>& _p);

	Point_t<T>& operator()(const T _x = T(), const T _y = T(), const T _z = T());
	Point_t<T>& operator+=(const Vector3_t<T>& _v);
	Point_t<T>& operator+=(const T& n);
	Point_t<T>& operator-=(const Vector3_t<T>& _v);
	Point_t<T>& operator-=(const T& n);
	Point_t<T>& operator*=(const Vector3_t<T>& _v);
	Point_t<T>& operator*=(const T& n);
	Point_t<T>& operator/=(const T& n);

	Point_t<T> operator+(const Vector3_t<T>& _v) const{	return Point_t<T>(*this) += _v;	};
	Point_t<T> operator+(const T& n) const{	return Point_t<T>(*this) += n;	};
	Point_t<T> operator-() const{	return Point_t<T>(*this) * T(-1);	};
	Point_t<T> operator-(const Vector3_t<T>& _v) const{	return Point_t<T>(*this) -= _v;	};
	Point_t<T> operator-(const T& n) const{	return Point_t<T>(*this) -= n;	};
	Point_t<T> operator*(const Vector3_t<T>& _v) const{	return Point_t<T>(*this) *= _v;	};
	Point_t<T> operator*(const T& n) const{	return Point_t<T>(*this) *= n;	};
	Point_t<T> operator/(const T& n) const{	return Point_t<T>(*this) /= n;	};

	Vector3_t<T> operator-(const Point_t<T>& _p) const;
	bool operator==(const Point_t<T>& _v);
	bool operator!=(const Point_t<T>& _v);
	T operator[](const unsigned int& i) const;
	T& operator[](const unsigned int& i);

	T Distance(const Point_t<T>& _p) const;
	Point_t<T> Center(const Point_t<T>& _p) const;

	void Display();
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const Point_t<T>& _p){
	return o << "p(" << _p.x << "," << _p.y << "," << _p.z << ")";
}

template<typename T>
struct Vector4_t
{
	T x, y, z, w;

	Vector4_t(const T _x = T(), const T _y = T(), const T _z = T(), const T _w = T()) : x(_x), y(_y), z(_z), w(_w){}
	Vector4_t(const Vector4_t<T>& v) = default;
	Vector4_t(const Vector2_t<T>& v) : x(v.x), y(v.y), z(T()), w(T()){};
	explicit Vector4_t(const Vector2_t<T>& v, const T _z = T(), const T _w = T()) : x(v.x), y(v.y), z(_z), w(_w){};
	explicit Vector4_t(const T _x, const Vector2_t<T>& v, const T _w = T()) : x(_x), y(v.x), z(v.y), w(_w){};
	explicit Vector4_t(const T _x, const T _y, const Vector2_t<T>& v) : x(_x), y(_y), z(v.x), w(v.y){};
	explicit Vector4_t(const Vector2_t<T>& v1, const Vector2_t<T>& v2) : x(v1.x), y(v1.y), z(v2.x), w(v2.y){};
	Vector4_t(const Vector3_t<T>& v) : x(v.x), y(v.y), z(v.z), w(T()){};
	explicit Vector4_t(const Vector3_t<T>& v, const T _w = T()) : x(v.x), y(v.y), z(v.z), w(_w){};
	explicit Vector4_t(const T _x, const Vector3_t<T>& v) : x(_x), y(v.x), z(v.y), w(v.z){};
	Vector4_t(const Point_t<T>& p) : x(p.x), y(p.y), z(p.z), w(T()){}
	explicit Vector4_t(const Point_t<T>& p, const T _w = T()) : x(p.x), y(p.y), z(p.z), w(_w){};
	explicit Vector4_t(const T _x, const Point_t<T>& p) : x(_x), y(p.x), z(p.y), w(p.z){};

	template<typename TT>
	friend std::ostream& operator<<(std::ostream& o, const Vector4_t<TT>& _v);

	Vector4_t<T>& operator()(const T _x = T(), const T _y = T(), const T _z = T(), const T _w = T());
	Vector4_t<T>& operator+=(const Vector4_t<T>& _v);
	Vector4_t<T>& operator+=(const T& n);
	Vector4_t<T>& operator-=(const Vector4_t<T>& _v);
	Vector4_t<T>& operator-=(const T& n);
	Vector4_t<T>& operator*=(const Vector4_t<T>& _v);
	Vector4_t<T>& operator*=(const T& n);
	Vector4_t<T>& operator/=(const T& n);

	Vector4_t<T> operator+(const Vector4_t<T>& _v) const{	return Vector4_t<T>(*this) += _v;	};
	Vector4_t<T> operator+(const T& n) const{	return Vector4_t<T>(*this) += n;	};
	Vector4_t<T> operator-() const{	return (*this) * T(-1);	};
	Vector4_t<T> operator-(const Vector4_t<T>& _v) const{	return Vector4_t<T>(*this) -= _v;	};
	Vector4_t<T> operator-(const T& n) const{	return Vector4_t<T>(*this) -= n;	};
	Vector4_t<T> operator*(const Vector4_t<T>& _v) const{	return Vector4_t<T>(*this) *= _v;	};
	Vector4_t<T> operator*(const T& n) const{	return Vector4_t<T>(*this) *= n;	};
	Vector4_t<T> operator/(const T& n) const{	return Vector4_t<T>(*this) /= n;	};
	bool operator==(const Vector4_t<T>& _v);
	bool operator!=(const Vector4_t<T>& _v);
	T operator[](const unsigned int& i) const;
	T& operator[](const unsigned int& i);

	T SquaredLength() const;
	T Length() const;
	T Dot(const Vector4_t<T>& _v) const;
	Vector4_t<T>& Normalize();
	Vector4_t<T> Normalized() const{	return Vector4_t<T>(*this).Normalize();	};

	void Display();

	static T const Dot(const Vector4_t<T>& _v1, const Vector4_t<T>& _v2){	return _v1.Dot(_v2);	}
	static T const SquaredDistance(const Vector4_t<T>& _v1, const Vector4_t<T>& _v2){	return (_v1 - _v2).SquaredLength();	}
	static T const Distance(const Vector4_t<T>& _v1, const Vector4_t<T>& _v2){	return (_v1 - _v2).Length();	}
	static Vector4_t<T> const Middle(const Vector4_t<T>& _v1, const Vector4_t<T>& _v2){	return (_v1 + _v2) / T(2);	}
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vector4_t<T>& _v){
	return o << "v(" << _v.x << "," << _v.y << "," << _v.z << "," << _v.w << ")";
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