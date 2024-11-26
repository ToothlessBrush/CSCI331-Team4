#include <iostream>
#include "blockBuilder.h"
#include "blockbuffer.h"

int main()
{
    BlockBuilder builder("../data/us_postal_codes.csv", "../data/blocks.csv", 512);
    if (builder.buildBlocks())
    {
        std::cout << "Blocks created successfully!\n";
    }
    else
    {
        std::cout << "Error creating blocks!\n";
    }

    BlockBuffer blockBuffer("../data/blocks.csv");

    std::vector<ZipCodeData> blockData = blockBuffer.get_block_data(0);

    for (const auto& data : blockData) {
        std::cout << data << std::endl;
    }
}