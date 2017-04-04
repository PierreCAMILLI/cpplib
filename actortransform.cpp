#include "include/actor.hpp"
#include "include/actortransform.hpp"

Vector3_t<double> const ActorTransform::GetPosition() const{
	Vector3_t<double> worldPosition(position);
	Actor * _actor = actor;

	while(actor->HasParent()){
		_actor = &(_actor->GetParent());
		worldPosition += _actor->GetTransform().GetLocalPosition();
	}

	return worldPosition;
}

void ActorTransform::SetWorldPosition(const Vector3_t<double> & _position){
	position += _position - GetPosition();
}