#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <random>
#include <vector>

class PerlinNoise{

	private:
		std::vector<int> p;

	 	double fade(const double& t) const;
	 	double lerp(const double& t, const double& a, const double& b) const;
	 	double grad(const int& hash, const double& x, const double& y, const double& z) const;

	public:
		PerlinNoise();
		PerlinNoise(const unsigned int& seed);

		double noise( double x, double y, double z) const;

		static float Noise2D(int x, int y);

};
