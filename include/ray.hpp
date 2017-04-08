#pragma once

#include "vector.hpp"

template <typename T>
struct Raycast_t{
	Vector3_t<T> origin;
	Vector3_t<T> direction;
	T maxDistance;

	Raycast_t(const Raycast_t& _raycast) = default;
	Raycast_t(const Vector3_t<T>& _origin, const Vector3_t<T>& _direction, const T & _maxDistance = (T)-1.0 ) :
		origin(_origin), direction(_direction), maxDistance(_maxDistance){}
};

typedef Raycast_t<double> Raycast;
typedef Raycast_t<float> Raycastf;
typedef Raycast_t<int> Raycasti;

template <typename T>
struct RaycastHit_t{
	bool hit = false;
	Vector3_t<T> origin;
	Vector3_t<T> point;
	Vector3_t<T> normal;

	RaycastHit_t(){}
	RaycastHit_t(const RaycastHit_t& _raycastHit) = default;

	template<typename TT>
	friend std::ostream& operator<<(std::ostream& o, const RaycastHit_t<TT>& _h);

	operator bool() const{	return hit;	}
	bool operator< (const RaycastHit_t<T> & _raycastHit){	return SquaredDistance() < _raycastHit.SquaredDistance();	}
	bool operator<=(const RaycastHit_t<T> & _raycastHit){	return SquaredDistance() <= _raycastHit.SquaredDistance();	}
	bool operator> (const RaycastHit_t<T> & _raycastHit){	return !((*this) <= _raycastHit);	}
	bool operator>=(const RaycastHit_t<T> & _raycastHit){	return !((*this) < _raycastHit);	}

	T SquaredDistance() const{	return Vector3_t<T>::SquaredDistance(origin, point);	}
	T Distance() const{	return Vector3_t<T>::Distance(origin, point);	}
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const RaycastHit_t<T>& _h){
	return o << "Hit{" << std::endl <<
			"\torigin: " << _h.origin << std::endl <<
			"\tpoint: " << _h.point << std::endl <<
			"\tnormal: " << _h.normal.Normalized() << std::endl <<
			"\tdistance: " << Vector3_t<T>::Distance(_h.origin,_h.point) << std::endl
			<< "}";
}

typedef RaycastHit_t<double> RaycastHit;
typedef RaycastHit_t<float> RaycastHitf;
typedef RaycastHit_t<int> RaycastHiti;

template <typename T>
struct Raycast2D_t{
	Vector2_t<T> origin;
	Vector2_t<T> direction;
	T maxDistance;

	Raycast2D_t(const Raycast2D_t& _raycast2d) = default;
	Raycast2D_t(const Vector2_t<T>& _origin, const Vector2_t<T>& _direction, const T & _maxDistance = (T)-1.0 ) :
		origin(_origin), direction(_direction), maxDistance(_maxDistance){}
};

typedef Raycast2D_t<double> Raycast2D;
typedef Raycast2D_t<float> Raycast2Df;
typedef Raycast2D_t<int> Raycast2Di;

template <typename T>
struct RaycastHit2D_t{
	bool hit = false;
	Vector2_t<T> origin;
	Vector2_t<T> point;
	Vector2_t<T> normal;

	RaycastHit2D_t(){}
	RaycastHit2D_t(const RaycastHit2D_t& _raycastHit2d) = default;

	template<typename TT>
	friend std::ostream& operator<<(std::ostream& o, const RaycastHit2D_t<TT>& _h);

	operator bool() const{	return hit;	}
	bool operator< (const RaycastHit2D_t<T> & _raycastHit2d){	return SquaredDistance() < _raycastHit2d.SquaredDistance();	}
	bool operator<=(const RaycastHit2D_t<T> & _raycastHit2d){	return SquaredDistance() <= _raycastHit2d.SquaredDistance();	}
	bool operator> (const RaycastHit2D_t<T> & _raycastHit2d){	return !((*this) <= _raycastHit2d);	}
	bool operator>=(const RaycastHit2D_t<T> & _raycastHit2d){	return !((*this) < _raycastHit2d);	}

	T SquaredDistance() const{	return Vector2_t<T>::SquaredDistance(origin, point);	}
	T Distance() const{	return Vector2_t<T>::Distance(origin, point);	}
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const RaycastHit2D_t<T>& _h){
	return o << "Hit2D{" << std::endl
			<< "\torigin: " << _h.origin << std::endl
			<< "\tpoint: " << _h.point << std::endl
			<< "\tnormal: " << _h.normal.Normalized() << std::endl
			<< "\tdistance: " << Vector2_t<T>::Distance(_h.origin,_h.point) << std::endl
			<< "}";
}

typedef RaycastHit2D_t<double> RaycastHit2D;
typedef RaycastHit2D_t<float> RaycastHit2Df;
typedef RaycastHit2D_t<int> RaycastHit2Di;