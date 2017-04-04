#pragma once

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "color.hpp"

typedef unsigned int ImageDimension;

class Image{
	private:
		Color * pixels;
		ImageDimension width, height;

		void Allocate(){	pixels = (Color *) malloc(sizeof(Color) * width * height);	}
	public:
		Image() : width(0), height(0){}
		Image(const std::string & _source);
		Image(const ImageDimension & _width, const ImageDimension & _height)
			: width(_width), height(_height){	Allocate();	}
		Image(const Image & _image) = default;

		Image Copy() const;
		void Release(){	free(pixels);	}
		void Export(const std::string & _destination);

		Color & operator()(const ImageDimension & _x, const ImageDimension & _y){	return pixels[(_y * width) + _x];	}
		Color operator()(const ImageDimension & _x, const ImageDimension & _y) const{	return pixels[(_y * width) + _x];	}

		ImageDimension const & GetWidth() const{	return width;	}
		ImageDimension const & GetHeight() const{	return height;	}

		void Filter(const Color & c);
		void ToCanvas(const Color & c1, const Color & c2, const ImageDimension & _size);
};