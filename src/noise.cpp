#include "noise.hpp"

// This is, of course, fine -- after all, no sane person would include a .cpp file
using namespace trsb;

NoiseGenerator::NoiseGenerator(int cell_width, int cell_height, int cells_x, int cells_y)
{
	this -> cell_width = cell_width;
	this -> cell_height = cell_height;

	this -> cells_x = cells_x;
	this -> cells_y = cells_y;

	width = cell_width * cells_x;
	height = cell_height * cells_y;

	noise = new float[width * height];
}

NoiseGenerator::~NoiseGenerator()
{
	delete noise;
}

int NoiseGenerator::GetWidth()
{
	return width;
}

int NoiseGenerator::GetHeight()
{
	return height;
}

float* NoiseGenerator::GetNoise()
{
	return noise;
}

void NoiseGenerator::GenerateNoise()
{

}

