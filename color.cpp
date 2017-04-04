#include "include/color.hpp"

void Color3::ClampValues01(){
	r = (r < 0.0f ? 0.0f : r > 1.0f ? 1.0f : r);
	g = (g < 0.0f ? 0.0f : g > 1.0f ? 1.0f : g);
	b = (b < 0.0f ? 0.0f : b > 1.0f ? 1.0f : b);
}

Color3 const Color3::Grayscale() const{
	return Color3((r + g + b) / 3.0f);

}

fixed const & Color3::MaxColorComponent() const{
	return (r >= g ? r : g >= b ? g : b);
}

void Color::ClampValues01(){
	r = (r < 0.0f ? 0.0f : r > 1.0f ? 1.0f : r);
	g = (g < 0.0f ? 0.0f : g > 1.0f ? 1.0f : g);
	b = (b < 0.0f ? 0.0f : b > 1.0f ? 1.0f : b);
	a = (a < 0.0f ? 0.0f : a > 1.0f ? 1.0f : a);
}

Color const Color::Grayscale() const{
	fixed mean = (r + g + b) / 3.0f;
	return Color(mean, mean, mean, a);

}

fixed const & Color::MaxColorComponent() const{
	return (r >= g ? r : g >= b ? g : b);
}