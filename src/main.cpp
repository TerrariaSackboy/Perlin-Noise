#include <cstdio>
#include <cstdlib>
#include "noise.hpp"

const char* argument_description =
"\
\tcells x (int): how many cells wide the noise is\n\
\tcells y (int): how many cells high the noise is\n\
\tcell w (int): the width of each individual cell\n\
\tcell h (int): the height of each individual cell\n\
\tseed (int): seed of the noise; defaults to 0\n\
\tout (string): path to the output image; defaults to noise.png\n";

int main(int argc, char* argv[])
{
	// Hacked-together CLI
	// TODO: make it less gross
	if (argc < 5)
	{
		printf("Usage: perlin-noise x y w h [s] [o]\n");
		printf("%s", argument_description);
		return 1;
	}

	int params[5] = {0};
	char path[257] = "noise.png";

	for (int i = 1; i < argc; i++)
	{
		// Make sure the length is fine
		int length = 0;
		while (length <= 257 && argv[i][length] != '\0')
		{
			length++;
		}

		if (length > 257)
		{
			printf("Argument %d is too long (%d); must be at most 256\n",
					i, length);
			return 1;
		}
		
		if (i <= 5)
		{
			sscanf(argv[i], "%d", params + i - 1);
		}
		else if (i == 6)
		{
			sscanf(argv[i], "%s", path);
		}
		else
			break;
	}

	srand(params[4]);

	trsb::NoiseGenerator generator(params[0],params[1],   params[2],params[3]);
	generator.GenerateNoise();

	return 0;
}

