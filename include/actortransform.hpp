#pragma once

#include "transform.hpp"

class Actor;

struct ActorTransform : public Transform{
	Actor * actor;

	ActorTransform(	Actor * const & _actor,
					const Vector3_t<double>& _position = Vector3_t<double>(0,0,0),
					const Vector3_t<double>& _rotation = Vector3_t<double>(0,0,0),
					const Vector3_t<double>& _scale = Vector3_t<double>(1,1,1))
					: Transform(_position, _rotation, _scale), actor(_actor){}
	ActorTransform(const ActorTransform& _transform) = default;

	Vector3_t<double> const GetPosition() const;

	void SetWorldPosition(const Vector3_t<double> & _position);
};