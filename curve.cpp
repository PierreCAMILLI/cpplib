#include "include/curve.hpp"

template<typename T>
Curve_t<T>::Curve_t(Vector2_t<T>* a_con, unsigned int size) : controls(){
	for(unsigned int i = 0; i < size; i++)
		controls.push_back(a_con[i]);
	sort();
}

template<typename T>
unsigned int Curve_t<T>::getIndexOf(const T& _x){
	for(unsigned int i = 0; i < controls.size(); i++){
		if(controls[i].x == _x)
			return i;
	}
	return -1;
}

template<typename T>
void Curve_t<T>::sort(){
	bool ordered;
	do{
		ordered = true;
		for(unsigned int i = 0; i < controls.size() - 1; i++){
			if(controls[i].x > controls[i+1].x){
				Vector2_t<T> temp = controls[i];
				controls[i] = controls[i+1];
				controls[i+1] = temp;
				ordered = false;
			}
		}
	}while(!ordered);
}

template<typename T>
Curve_t<T> Curve_t<T>::point(const T& _x, const T& _y){
	int index = getIndexOf(_x);
	if(index != -1)
		controls[index].y = _y;
	else{
		controls.push_back(Vector2_t<T>(_x,_y));
		sort();
	}
	return *this;
}

template<typename T>
Curve_t<T> Curve_t<T>::point(const Vector2_t<T>& _v){
	int index = getIndexOf(_v.x);
	if(index != -1)
		controls[index].y = _v.y;
	else{
		controls.push_back(_v);
		sort();
	}
	return *this;
}

template<typename T>
bool Curve_t<T>::contains(const T& _x){
	for(unsigned int i = 0; i < controls.size(); i++){
		if(controls[i].x == _x)
			return true;
	}
	return false;
}

template<typename T>
bool Curve_t<T>::contains(const T& _x, const T& _y){
	for(unsigned int i = 0; i < controls.size(); i++){
		if(controls[i].x == _x && controls[i].y == _y)
			return true;
	}
	return false;
}

template<typename T>
bool Curve_t<T>::move(const unsigned int& i, const unsigned int& _x){
	if(i >= size())
		return false;
	controls[i].x = _x;
	sort();
	return true;
}

template<typename T>
bool Curve_t<T>::remove(const unsigned int& i)
{
	if(i > size())
		return false;
	controls.erase(controls.begin() + i);
	return true;
}

template<typename T>
T const Curve_t<T>::Linear(const T& _x){
	if(size() == 0)
		return default_value;
	if(size() == 1)
		return controls[0].y;
	int index = getIndexOf(_x);
	if(index != -1)
		return controls[index].y;
	// Entre -infini et le second point de la courbe
	unsigned int X0 = 0, X1 = 1;
	// Entre +infini et l'avant-dernier point de la courbe
	if(_x > controls[size()-2].x){
		X0 = size() - 2;	X1 = size() - 1;
	// Entre le second et l'avant-dernier point de la courbe
	}else if (_x > controls[0].x){
		for(unsigned int i = 1; i < size() - 1; i++){
			if(_x < controls[i].x){
				X0 = i - 1;	X1 = i;
				break;
			}
		}
	}
	T Y = (controls[X1].y - controls[X0].y) / (controls[X1].x - controls[X0].x);
	T val = controls[X0].y + ((_x - controls[X0].x) * Y);
	return val;
}

template<typename T>
T const Curve_t<T>::Sine(const T& _x){
	if(size() == 0)
		return default_value;
	if(_x <= controls[0].x)
		return controls[0].y;
	if(_x >= controls[size()-1].x)
		return controls[size()-1].y;
	for(unsigned int i = 0; i < size() - 1; i++){
		if(_x < controls[i+1].x){
			T Y = controls[i].y - controls[i+1].y;
			if(Y == 0)
				return controls[i].y;
			T X = controls[i].x - controls[i+1].x;
			T _X = (_x - controls[i].x) / X;
			T _Y = ((cos(_X * CURVE_PI) + 1) / 2) * Y;
			return controls[i].y + _Y;
		}
	}
	return default_value;
}

template class Curve_t<double>;
template class Curve_t<float>;
template class Curve_t<int>;