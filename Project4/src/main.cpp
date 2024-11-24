#include <iostream>
#include "blockBuilder.h"

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
}