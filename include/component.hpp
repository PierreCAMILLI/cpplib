#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Actor;

class ActorComponent{
	private:
		Actor * actor = nullptr;
		bool enabled = true;
	public:
		virtual void Start(){} 

};