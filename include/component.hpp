#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "actor.hpp"
#include "actortransform.hpp"

class ActorComponent{
	private:
		Actor * actor = nullptr;
		bool enabled = true;
	public:
		virtual void Start(){}

		Actor const & GetParent() const{	return *actor;	}
		Actor & GetParent(){	return *actor;	}

		/*
		ActorTransform const & GetTransform() const{	return actor->GetTransform();	}
		ActorTransform & GetTransform(){	return actor->GetTransform();	}
		*/
};