#include "include/image.hpp"

Image::Image(const std::string & _source){
	// Récupération du fichier
	FILE * file = fopen(_source.c_str(), "rb");
	if(!file){
		printf("ERREUR: Le fichier n'a pas pu être ouvert.");
		return;
	}

	const int headerSize = 54;
	unsigned char info[headerSize];
	fread(info, sizeof(unsigned char), headerSize, file);

	// Extraction des informations
	width = *(int*)&info[18];
	height = *(int*)&info[22];

	int size = 3 * width * height;
	unsigned char * data = new unsigned char[size];
	fread(data, sizeof(unsigned char), size, file);
	fclose(file);

	// Allocation de l'espace mémoire nécessaire
	Allocate();

	// Conversion et copie des pixels 
	// /!\ Couleurs classées dans l'ordre GRB dans le fichier
	for(ImageDimension i = 0; i < (width * height); ++i){
		pixels[i].g = (float)data[headerSize + (i * 3)] / 255.f;
		pixels[i].r = (float)data[headerSize + (i * 3) + 1] / 255.f;
		pixels[i].b = (float)data[headerSize + (i * 3) + 2] / 255.f;
	}

	free(data);
}

Image Image::Copy() const{
	Image im(width, height);
	for(ImageDimension i = 0; i < (width * height); ++i){
		im.pixels[i] = pixels[i];
	}
	return im;
}

void Image::Export(const std::string & _destination){
	// Déclaration du header du fichier
	typedef struct{
		unsigned int	bfSize;			// Size of file
		unsigned short	bfReserved1;	// Reserved
		unsigned short	bfReserved2;	// ...
		unsigned int	bfOffBits;		// Offset to bitmap data
	} BITMAPFILEHEADER;

	typedef struct{
		unsigned int	biSize;			// Size of info header
		int				biWidth;		// Width of image
		int				biHeight;		// Height of image
		unsigned short	biPlanes;		// Number of color planes
		unsigned short	biBitCount;		// Number of bits per pixel
		unsigned int	biCompression;	// Type of compression to use
		unsigned int 	biSizeImage;	// Size of image data
		int				biXPelsPerMeter;// X pixels per meter
		int				biYPelsPerMeter;// Y pixels per meter
		unsigned int	biClrUsed;		// Number of colors used
		unsigned int	biClrImportant;	// Number of important colors
	} BITMAPINFOHEADER;

	BITMAPFILEHEADER bfh;
	BITMAPINFOHEADER bih;

	// Paramétrage du header du fichier
	unsigned short bfType = 0x4d42;
	bfh.bfReserved1 = 0;
	bfh.bfReserved2 = 0;
	bfh.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	bfh.bfOffBits = 0x36;

	bih.biSize = sizeof(BITMAPINFOHEADER);
	bih.biWidth = width;
	bih.biHeight = height;
	bih.biPlanes = 1;
	bih.biBitCount = 24;
	bih.biCompression = 0;
	bih.biSizeImage = 0;
	bih.biXPelsPerMeter = 5000;
	bih.biYPelsPerMeter = 5000;
	bih.biClrUsed = 0;
	bih.biClrImportant = 0;

	// Création du fichier
	FILE * file = fopen(_destination.c_str(), "wb");
	if(!file){
		printf("ERREUR: Le fichier n'a pas pu être écrit.");
		return;
	}

	// Ecriture des ĥeaders
	fwrite(&bfType,1,sizeof(bfType),file);
	fwrite(&bfh, 1, sizeof(bfh), file);
	fwrite(&bih, 1, sizeof(bih), file);

	// Ecriture du fichier
	for (int y = 0; y < bih.biHeight; ++y) /*Scanline loop backwards*/
    {
    	for (int x = 0; x < bih.biWidth; ++x) /*Column loop forwards*/
        {
	        /*compute some pixel values*/
	        Color3 c = (*this)(x,y).RGB();
	        unsigned char r = 255 * c.r;
	        unsigned char g = 255 * c.g;
	        unsigned char b = 255 * c.b;
	        fwrite(&b, 1, 1, file);
	        fwrite(&g, 1, 1, file);
	        fwrite(&r, 1, 1, file);
        }
    }
	fclose(file);
}

void Image::Filter(const Color & c){
	for(ImageDimension i = 0; i < (width * height); ++i){
		pixels[i] *= c;
	}
}

void Image::ToCanvas(const Color & c1, const Color & c2, const ImageDimension & _size){
	for(ImageDimension i = 0; i < width; ++i){
		for(ImageDimension j = 0; j < height; ++j){
			int	xCheck = ((((int) floor(i / _size)) % 2) == 0 ? 1 : -1),
				yCheck = ((((int) floor(j / _size)) % 2) == 0 ? 1 : -1);
			if( xCheck * yCheck > 0)
				(*this)(i,j) = c1;
			else
				(*this)(i,j) = c2;
		}
	}
}