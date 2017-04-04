#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>

#include "multitypescontainer.hpp"
#include "actortransform.hpp"

class ActorComponent;

typedef unsigned long long ActorLayer;
typedef std::string ActorName;
typedef MultitypesContainer<ActorComponent> ActorComponents;

constexpr ActorLayer DEFAULT_LAYER = 1;

class Actor{
	typedef std::vector<Actor> ActorChildren;

	private:
		Actor * parent;

		bool enabled = true;
		ActorLayer layer = DEFAULT_LAYER;
		ActorName name;
		ActorTransform transform;

		ActorChildren children;
		ActorComponents components;

		void DisplayTreeChildren(const unsigned int& tab = 0);
		Actor(Actor * const& _parent, const Actor& _actor) : Actor(_actor){	parent = _parent;	}
	public:
		Actor(const ActorLayer& _layer = DEFAULT_LAYER, const ActorName& _name = "New Actor");
		Actor(const Actor& _actor) = default;

		bool HasParent(){	return parent != nullptr;	}
		Actor const & GetParent() const{	return *parent;	}
		Actor& GetParent(){	return *parent;	}
		
		bool const & IsEnabled() const{	return enabled;	}
		bool& IsEnabled() {	return enabled;	}
		void Enable(){	enabled = true;	}
		void Disable(){	enabled = false;	}

		ActorLayer const & GetLayer() const{	return layer;	}
		void SetLayer(const ActorLayer& _layer){	if(_layer > 0)	layer = _layer;	}
		bool AreLayersCorresponding(const ActorLayer& _layer){	return (layer & _layer) > 0;	}

		ActorName const & GetName() const{	return name;	}
		void Rename(const ActorName& _name) {	name = _name;	}

		ActorTransform const & GetTransform() const{	return transform;	}
		ActorTransform& GetTransform(){	return transform;	}

		ActorChildren const & GetChildren() const{	return children;	}
		ActorChildren& GetChildren(){	return children;	}
		void AppendChild(const Actor& child);
		void RemoveChild(const unsigned int& index){	children.erase(children.begin() + index);	}
		void RemoveChild(const ActorName& _name);
		void RemoveChildren(const ActorName& _name);
		void DisplayTreeChildren(){	DisplayTreeChildren(0);	}

		template<typename T>
		void AddComponent(const T & _component){	components.AddElement<T>(_component);	}
		template<typename T>
		T * const GetComponent(){	return components.GetElement<T>();	}
		template<typename T>
		ActorComponents const GetComponents() const{	return components.GetElements<T>();	}

		Actor& operator<<(const Actor& child){	AppendChild(child);	return (*this);	}
};