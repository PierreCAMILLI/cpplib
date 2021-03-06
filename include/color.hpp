#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

typedef float fixed;

struct Color3{
	fixed r, g, b;

	Color3() : r(fixed()), g(fixed()), b(fixed()){}
	Color3(const fixed & _c) : r(_c), g(_c), b(_c){}
	Color3(const fixed & _r, const fixed & _g, const fixed & _b)
		: r(_r), g(_g), b(_b){}
	Color3(const Color3 & _c) = default;

	Color3 operator-() const{	return Color3(-r, -g, -b);	}
	Color3& operator+=(const Color3 & _c){	r += _c.r;	g += _c.g;	b += _c.b;	return (*this);	}
	Color3& operator-=(const Color3 & _c){	return (*this) += (- _c);	}
	Color3& operator*=(const Color3 & _c){	r *= _c.r;	g *= _c.g;	b *= _c.b;	return (*this);	}
	Color3& operator/=(const Color3 & _c){	r /= _c.r;	g /= _c.g;	b /= _c.b;	return (*this);	}

	Color3 operator+(const Color3 & _c) const{	return Color3(*this) += _c;	}
	Color3 operator-(const Color3 & _c) const{	return Color3(*this) -= _c;	}
	Color3 operator*(const Color3 & _c) const{	return Color3(*this) *= _c;	}
	Color3 operator/(const Color3 & _c) const{	return Color3(*this) /= _c;	}

	friend std::ostream& operator<<(std::ostream& o, const Color3& _c);

	void ClampValues01();
	Color3 const Grayscale() const;
	fixed const & MaxColorComponent() const;

	static Color3 const Lerp(const Color3 & c1, const Color3 & c2, const float & _delta);

	static Color3 const Black(){	return Color3(fixed(0), fixed(0), fixed(0));	}
	static Color3 const Blue(){		return Color3(fixed(0), fixed(0), fixed(1));	}
	static Color3 const Green(){	return Color3(fixed(0), fixed(1), fixed(0));	}
	static Color3 const Cyan(){		return Color3(fixed(0), fixed(1), fixed(1));	}
	static Color3 const Red(){		return Color3(fixed(1), fixed(0), fixed(0));	}
	static Color3 const Magenta(){	return Color3(fixed(1), fixed(0), fixed(1));	}
	static Color3 const Yellow(){	return Color3(fixed(1), fixed(1), fixed(0));	}
	static Color3 const White(){	return Color3(fixed(1), fixed(1), fixed(1));	}
};

inline std::ostream& operator<<(std::ostream& o, const Color3& _c){
	return o << "c(" << _c.r << "," << _c.g << "," << _c.b << ")";
}

struct Color{
	fixed r, g, b, a;

	Color() : r(fixed()), g(fixed()), b(fixed()), a(fixed()){}
	Color(const fixed & _c) : r(_c), g(_c), b(_c), a(_c){}
	Color(const fixed & _r, const fixed & _g, const fixed & _b, const fixed & _a = fixed(1))
		: r(_r), g(_g), b(_b), a(_a){}
	Color(const Color3 & _c, const fixed & _a = fixed(1))
		: r(_c.r), g(_c.g), b(_c.b), a(_a){}
	Color(const Color & _c) = default;

	Color operator-() const{	return Color(-r, -g, -b, -a);	}
	Color& operator+=(const Color & _c){	r += _c.r;	g += _c.g;	b += _c.b;	a += _c.a;	return (*this);	}
	Color& operator-=(const Color & _c){	return (*this) += (- _c);	}
	Color& operator*=(const Color & _c){	r *= _c.r;	g *= _c.g;	b *= _c.b;	a *= _c.a;	return (*this);	}
	Color& operator/=(const Color & _c){	r /= _c.r;	g /= _c.g;	b /= _c.b;	a /= _c.a;	return (*this);	}

	Color operator+(const Color & _c) const{	return Color(*this) += _c;	}
	Color operator-(const Color & _c) const{	return Color(*this) -= _c;	}
	Color operator*(const Color & _c) const{	return Color(*this) *= _c;	}
	Color operator/(const Color & _c) const{	return Color(*this) /= _c;	}

	friend std::ostream& operator<<(std::ostream& o, const Color& _c);

	Color3 RGB() const{	return Color3(r,g,b);	}
	void ClampValues01();
	Color const Grayscale() const;
	fixed const & MaxColorComponent() const;

	static Color const Lerp(const Color & c1, const Color & c2, const float & _delta);

	static Color const Blank(){		return Color(fixed(0), fixed(0), fixed(0), fixed(0));	}
	static Color const Black(){		return Color(fixed(0), fixed(0), fixed(0));	}
	static Color const Blue(){		return Color(fixed(0), fixed(0), fixed(1));	}
	static Color const Green(){		return Color(fixed(0), fixed(1), fixed(0));	}
	static Color const Cyan(){		return Color(fixed(0), fixed(1), fixed(1));	}
	static Color const Red(){		return Color(fixed(1), fixed(0), fixed(0));	}
	static Color const Magenta(){	return Color(fixed(1), fixed(0), fixed(1));	}
	static Color const Yellow(){	return Color(fixed(1), fixed(1), fixed(0));	}
	static Color const White(){		return Color(fixed(1), fixed(1), fixed(1));	}
};

inline std::ostream& operator<<(std::ostream& o, const Color& _c){
	return o << "c(" << _c.r << "," << _c.g << "," << _c.b << "," << _c.a << ")";
}