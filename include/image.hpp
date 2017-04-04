#pragma once

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
		Image(const std::string & _source){	Import(_source);	}
		Image(const ImageDimension & _width, const ImageDimension & _height)
			: width(_width), height(_height){	Allocate();	}
		Image(const Image & _image) = default;

		Image Copy() const;
		void Release(){	free(pixels);	}

		Color & operator()(const ImageDimension & _x, const ImageDimension & _y){	return pixels[(_y * width) + _x];	}
		Color operator()(const ImageDimension & _x, const ImageDimension & _y) const{	return pixels[(_y * width) + _x];	}

		ImageDimension const & GetWidth() const{	return width;	}
		ImageDimension const & GetHeight() const{	return height;	}

		void Import(const std::string & _source);
		void Export(const std::string & _destination);
};