#include "noise.hpp"

int main(int argc, char* argv[])
{
	trsb::NoiseGenerator generator(4,4, 4,4);
	generator.GenerateNoise();

	return 0;
}

