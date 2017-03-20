#pragma once

#include "includes.hpp"

template<typename T>
struct Vector2_t;

template<typename T>
struct Vector3_t;

template <typename T>
struct Raycast_t{
	Vector3_t<T> origin;
	Vector3_t<T> direction;
	T maxDistance;

	Raycast_t(const Vector3_t<T>& _origin, const Vector3_t<T>& _direction, const T & _maxDistance = std::numeric_limits<T>::max() ) :
		origin(_origin), direction(_direction), maxDistance(_maxDistance){}
};

template <typename T>
struct RaycastHit_t{
	Vector3_t<T> point;
	Vector3_t<T> normal;
	T distance;

	RaycastHit_t(const Vector3_t<T>& _point) : point(_point){}
};

template <typename T>
struct Raycast2D_t{
	Vector2_t<T> origin;
	Vector2_t<T> direction;
	T maxDistance;

	Raycast2D_t(const Vector2_t<T>& _origin, const Vector2_t<T>& _direction, const T & _maxDistance = std::numeric_limits<T>::max() ) :
		origin(_origin), direction(_direction), maxDistance(_maxDistance){}
};

template <typename T>
struct RaycastHit2D_t{
	Vector2_t<T> point;
	Vector2_t<T> normal;
	T distance;

	RaycastHit2D_t(const Vector2_t<T>& _point) : point(_point){}
};