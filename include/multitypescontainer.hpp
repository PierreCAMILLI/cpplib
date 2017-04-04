#pragma once

#include "stdio.h"
#include "stdlib.h"

#include <vector>

template<typename Base>
class MultitypesContainer{
	typedef std::vector<Base*> BaseContainer;

	private:
		BaseContainer container;
	public:
		MultitypesContainer(){}
		MultitypesContainer(const MultitypesContainer& _container) = default;

		BaseContainer const & GetVector() const{	return container;	}
		BaseContainer & GetVector(){	return container;	}

		template<typename Derived>
		void AddElement(const Derived & _element){	container.push_back(new Derived(_element));	}
		template<typename Derived>
		void AddElement(Derived * const & _element){	container.push_back(_element);	};
		void AddElements(const BaseContainer& _elements){	container.insert(container.begin(), _elements.begin(), _elements.end());	};

		template<typename Derived>
		Derived * const GetElement();
		template<typename Derived>
		const std::vector<Derived*> GetElements() const;

		bool RemoveElement(Base * const & _element);
		bool RemoveElements(Base * const & _element);
		template<typename Derived>
		bool RemoveElement();
		template<typename Derived>
		bool RemoveElements();

		unsigned int const & Size() const{	return container.size();	} 
		void Reserve(const unsigned int & _size){	container.reserve(_size);	}
};

template<typename Base>
template<typename Derived>
Derived * const MultitypesContainer<Base>::GetElement(){
	for(unsigned int i = 0; i < container.size(); ++i){
		if(Derived * pointer = dynamic_cast<Derived*>(container[i])){
			return pointer;
		}
	}
	return NULL;
}

template<typename Base>
template<typename Derived>
const std::vector<Derived*> MultitypesContainer<Base>::GetElements() const{
	std::vector<Derived*> pointers;
	for(unsigned int i = 0; i < container.size(); ++i){
		if(Derived * pointer = dynamic_cast<Derived*>(container[i])){
			pointers.push_back(pointer);
		}
	}
	return pointers;
}

template<typename Base>
bool MultitypesContainer<Base>::RemoveElement(Base * const & _element){
	for(unsigned int i = 0; i < container.size(); ++i){
		if(_element == container[i]){
			container.erase(container.begin() + i);
			return true;
		}
	}
	return false;
}

template<typename Base>
bool MultitypesContainer<Base>::RemoveElements(Base * const & _element){
	bool removed = false;

	for(unsigned int i = 0; i < container.size(); ++i){
		while(i < container.size() && _element == container[i]){
			container.erase(container.begin() + i);
			removed = true;
		}
	}
	return removed;
}

template<typename Base>
template<typename Derived>
bool MultitypesContainer<Base>::RemoveElement(){
	for(unsigned int i = 0; i < container.size(); ++i){
		if(dynamic_cast<Derived*>(container[i])){
			container.erase(container.begin() + i);
			return true;
		}
	}
	return false;
}

template<typename Base>
template<typename Derived>
bool MultitypesContainer<Base>::RemoveElements(){
	bool removed = false;
	for(unsigned int i = 0; i < container.size(); ++i){
		while(i < container.size() && dynamic_cast<Derived*>(container[i])){
			container.erase(container.begin() + i);
			removed = true;
		}
	}
	return removed;
}