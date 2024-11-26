#include "blockBuilder.h"

Block::Block(unsigned int number) : blockNumber(number) {}

// Add a record to the block
void Block::addRecord(const std::string &record)
{
    records.push_back(record);
}

// Check if the block is empty
bool Block::isEmpty() const
{
    return records.empty();
}

// Get the size of the block (including newline and commas)
unsigned int Block::getSize() const
{
    unsigned int size = 0;
    for (const auto &record : records)
    {
        size += record.size() + 1; // +1 for newline or comma
    }
    return size;
}

// Write the block's content to an output stream
void Block::writeToFile(std::ofstream &outputFile) const
{
    outputFile << blockNumber << ":";
    for (size_t i = 0; i < records.size(); ++i)
    {
        outputFile << records[i];
        if (i < records.size() - 1)
        {
            outputFile << '\n';
        }
    }
    outputFile << "\n";
}

BlockBuilder::BlockBuilder(const std::string &inputFile, const std::string &outputFile, int size)
    : inputFileName(inputFile), outputFileName(outputFile), blockSize(size) {}

bool BlockBuilder::buildBlocks()
{
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);
    if (!inputFile.is_open() || !outputFile.is_open())
    {
        return false;
    }

    unsigned int blockNumber = 0;
    Block currentBlock(blockNumber);
    std::string line;

    std::getline(inputFile, line);

    while (std::getline(inputFile, line))
    {
        unsigned int lineSize = line.size() + 1; // +1 for newline character
        if (currentBlock.getSize() + lineSize > blockSize)
        {
            currentBlock.writeToFile(outputFile);

            // Start a new block
            ++blockNumber;
            currentBlock = Block(blockNumber);
        }

        currentBlock.addRecord(line);
    }

    // Write any remaining records to the file
    if (!currentBlock.isEmpty())
    {
        currentBlock.writeToFile(outputFile);
    }

    inputFile.close();
    outputFile.close();
    return true;
}
