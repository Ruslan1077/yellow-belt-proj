#include <iostream>
#include <cstdint>
#include <vector>

struct Block
{
	uint16_t _width  = 0;
	uint16_t _height = 0;
	uint16_t _length = 0;
};



int main()
{
	size_t  count_of_blocks = 0;
	uint16_t ro				= 0;

	std::cin >> count_of_blocks >> ro;

	std::vector<Block> blocks;
	for (size_t i = 0; i < count_of_blocks; i++)
	{
		Block tmp;
		std::cin >> tmp._width >> tmp._height >> tmp._length;
		blocks.push_back(tmp);
	}

	uint64_t common_weight = 0;
	for (Block& block : blocks)
	{
		common_weight += static_cast<uint64_t>(block._width) * static_cast<uint64_t>(block._height) * static_cast<uint64_t>(block._length) * static_cast<uint64_t>(ro);
	}

	std::cout << common_weight << std::endl;

	return 0;
}
