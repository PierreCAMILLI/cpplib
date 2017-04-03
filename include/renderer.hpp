#pragma once

#include "component.hpp"

class Renderer : public ActorComponent{
	public:
		int a;

		Renderer(const int & _a) : a(_a){}
};