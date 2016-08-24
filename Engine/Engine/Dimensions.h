#ifndef DIMENSIONS_H
#define DIMENSIONS_H

class Dimensions
{
public:
	void grow(float multiplier);

	//Copy constructor
	Dimensions(const int width, const int height) : width_(width), height_(height) {}

private:
	//Essential member variables
	int height_;
	int width_;
};

#endif