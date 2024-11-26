#include "blockbuffer.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Constructor to initialize BlockBuffer with the file name
BlockBuffer::BlockBuffer(const std::string& file) : Buffer(file) {
    std::ifstream fileStream(file);
    if (!fileStream.is_open()) {
        std::cerr << "Error: Unable to open file " << file << std::endl;
        return;
    }
    populate_block_map(fileStream);
    fileStream.close();
}

void BlockBuffer::populate_block_map(std::ifstream& file) {
    std::string line;
    int currentBlockNumber = -1;

    while (std::getline(file, line)) {
        if (line.find(':') != std::string::npos) {
            int end = line.find(':');
            currentBlockNumber = stoi(line.substr(0, end));
            line = line.substr(end + 1);
            blockMap[currentBlockNumber] = {this->tokenize_line(line)};
        } else {
            blockMap[currentBlockNumber].push_back(this->tokenize_line(line));
        }
    }
}

// Method to retrieve zip code data for a specific block
std::vector<ZipCodeData> BlockBuffer::get_block_data(int blockNumber) {
    auto it = blockMap.find(blockNumber);
    if (it != blockMap.end()) {
        return it->second;
    }
    return {}; // Return an empty vector if block is not found
}
