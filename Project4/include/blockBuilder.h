#ifndef BLOCK_BUILDER_H
#define BLOCK_BUILDER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Class to represent a block of records
class Block
{
private:
    unsigned int blockNumber;
    std::vector<std::string> records;

public:
    Block(unsigned int number);

    // Add a record to the block
    void addRecord(const std::string &record);

    // Check if the block is empty
    bool isEmpty() const;

    // Get the size of the block (including newline and commas)
    unsigned int getSize() const;

    // Write the block's content to an output stream
    void writeToFile(std::ofstream &outputFile) const;
};

// Class responsible for building blocks from an input file
class BlockBuilder
{
private:
    std::string inputFileName;
    std::string outputFileName;
    int blockSize;

public:
    BlockBuilder(const std::string &inputFile, const std::string &outputFile, int size = 512);

    // Function to create blocks from the input file and save them to the output file
    bool buildBlocks();
};

#endif // BLOCK_BUILDER_H
