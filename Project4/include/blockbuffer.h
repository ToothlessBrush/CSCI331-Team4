#ifndef BLOCKBUFFER_H
#define BLOCKBUFFER_H

#include "buffer.h"
#include <map>

/**
 * @brief The BlockBuffer class extends Buffer and maps block numbers to zip code data.
 */
class BlockBuffer : public Buffer {
    std::map<int, std::vector<ZipCodeData>> blockMap; ///< Map block numbers to arrays of ZipCodeData.

    /**
     * @brief Override method to populate blockMap from the file.
     * 
     * @param file The input file stream.
     */
    void populate_block_map(std::ifstream& file);

public:
    /**
     * @brief Constructs a BlockBuffer object that reads data from the specified file.
     * 
     * @param file The path to the input CSV file.
     */
    BlockBuffer(const std::string&);

    /**
     * @brief Retrieves the vector of ZipCodeData for a specific block number.
     * 
     * @param blockNumber The block number to fetch data for.
     * @return A vector of ZipCodeData for the given block number.
     */
    std::vector<ZipCodeData> get_block_data(int blockNumber);
};

#endif // BLOCKBUFFER_H
