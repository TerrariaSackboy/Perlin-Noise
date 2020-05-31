#ifndef __NOISE_HPP__
#define __NOISE_HPP__

namespace trsb
{
	class NoiseGenerator
	{
	private:
		int width;
		int height;
		int cell_width;
		int cell_height;
		int cells_x;
		int cells_y;

		float* noise;
		
	public:
		NoiseGenerator(int cell_width, int cell_height, int cells_x, int cells_y);

		~NoiseGenerator();

		int GetWidth();
		int GetHeight();

		float* GetNoise();

		void GenerateNoise();
	};
}

#endif//__NOISE_HPP__

