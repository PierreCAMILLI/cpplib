#include "include/color.hpp"

void Color3::ClampValues01(){
	r = (r < fixed(0) ? fixed(0) : r > fixed(1) ? fixed(1) : r);
	g = (g < fixed(0) ? fixed(0) : g > fixed(1) ? fixed(1) : g);
	b = (b < fixed(0) ? fixed(0) : b > fixed(1) ? fixed(1) : b);
}

Color3 const Color3::Grayscale() const{
	return Color3((r + g + b) / fixed(3));

}

fixed const & Color3::MaxColorComponent() const{
	return (r >= g ? r : g >= b ? g : b);
}

Color3 const Color3::Lerp(const Color3 & c1, const Color3 & c2, const float & _delta){
	if(_delta <= fixed(0))
		return c1;
	if(_delta >= fixed(1))
		return c2;
	return (c2 * _delta) + c1 * (fixed(1) - _delta);
}

void Color::ClampValues01(){
	r = (r < fixed(0) ? fixed(0) : r > fixed(1) ? fixed(1) : r);
	g = (g < fixed(0) ? fixed(0) : g > fixed(1) ? fixed(1) : g);
	b = (b < fixed(0) ? fixed(0) : b > fixed(1) ? fixed(1) : b);
	a = (a < fixed(0) ? fixed(0) : a > fixed(1) ? fixed(1) : a);
}

Color const Color::Grayscale() const{
	fixed mean = (r + g + b) / fixed(3);
	return Color(mean, mean, mean, a);

}

fixed const & Color::MaxColorComponent() const{
	return (r >= g ? r : g >= b ? g : b);
}

Color const Color::Lerp(const Color & c1, const Color & c2, const float & _delta){
	if(_delta <= fixed(0))
		return c1;
	if(_delta >= fixed(1))
		return c2;
	return (c2 * _delta) + c1 * (fixed(1) - _delta);
}