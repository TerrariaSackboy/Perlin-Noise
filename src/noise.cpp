#include <cmath>
#include <algorithm>
#include <random>
#include "noise.hpp"
#include "vector2.hpp"

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
	for (int cell_x = 0; cell_x < cells_x; cell_x++)
	{
		for (int cell_y = 0; cell_y < cells_y; cell_y++)
		{
			int offset_x = cell_x * cell_width;
			int offset_y = cell_y * cell_height;

			// TODO: Possibly don't use the c random function
			double angle = (rand() / (double)RAND_MAX) * 2 * M_PI;
			Vector2 angle_vector(cos(angle), sin(angle));

			for (int x = 0; x < cell_width; x++)
			{	
				for (int y = 0; y < cell_width; y++)
				{
					// Convert the local (x,y) position into a Vector2
					Vector2 position((double)x / (cell_width - 1) - 0.5,
							(double)y / (cell_width - 1) - 0.5);
					float value = angle_vector.Dot(position) * position.Magnitude();
					value = value + 0.5;
					value = std::max(std::min(value, 1.0f), 0.0f);

					noise[offset_x+x + width * (offset_y+y)] = value;
				}

			}
		}
	}
}

