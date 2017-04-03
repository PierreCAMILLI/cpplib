#include "actor.hpp"

void Actor::AppendChild(const Actor& child){
	children.push_back(Actor(this,child));
}

void Actor::RemoveChild(const ActorName& _name){
	for(unsigned int i = 0; i < children.size(); ++i){
		if(children[i].name == _name){
			children.erase(children.begin() + i);	return;
		}
	}
}

void Actor::RemoveChildren(const ActorName& _name){
	for(unsigned int i = 0; i < children.size(); ++i){
		if(children[i].name == _name){
			children.erase(children.begin() + i);
		}
	}
}

void Actor::DisplayTreeChildren(const unsigned int& tab){
	for(unsigned int i = 0; i < tab; ++i)	std::cout << "\t";
	std::cout << name << std::endl;
	for(unsigned int i = 0; i < children.size(); ++i)	children[i].DisplayTreeChildren(tab + 1);
}

template<typename T>
Vector3_t<T> const Transform_t<T>::GetPosition() const{
	Vector3_t<T> worldPosition(position);
	Actor * _actor = actor;

	while(actor->HasParent()){
		_actor = _actor->GetParent();
		worldPosition += _actor->GetTransform().GetLocalPosition();
	}

	return worldPosition;
}