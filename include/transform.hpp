#pragma once

#include "vector.hpp"

class Actor;

template <typename T>
struct Transform_t
{
	Actor * actor;

	Vector3_t<T> position;
	Vector3_t<T> rotation;
	Vector3_t<T> scale;

	Transform_t(Actor * const& _actor,
				const Vector3_t<T>& _position = Vector3_t<T>(T(0),T(0),T(0)),
				const Vector3_t<T>& _rotation = Vector3_t<T>(T(0),T(0),T(0)),
				const Vector3_t<T>& _scale = Vector3_t<T>(T(1),T(1),T(1)))
				: actor(_actor), position(_position), rotation(_rotation), scale(_scale){}
	Transform_t(const Transform_t<T>& _transform) = default;

	void Translate(const Vector3_t<T>& translation){	position += translation;	}
	void Rotate(const Vector3_t<T>& rotate){	rotation += rotate;	}
	void Rescale(const Vector3_t<T>& rescale){	scale *= rescale;	}

	Vector3_t<T> const & GetLocalPosition() const{	return position;	}
	Vector3_t<T> const & GetLocalEulerAngles() const{	return rotation;	}
	Vector3_t<T> const & GetLocalScale() const{	return scale;	}

	Vector3_t<T> & GetLocalEulerAngles(){	return rotation;	}
	Vector3_t<T> & GetLocalPosition(){	return position;	}
	Vector3_t<T> & GetLocalScale(){	return scale;	}

	Vector3_t<T> const GetPosition() const;
};

typedef Transform_t<double> Transform;
typedef Transform_t<float> Transformf;
typedef Transform_t<int> Transformi;