/**
 * @file buffer.h
 */
#ifndef BUFFER_H
#define BUFFER_H

#include <string>
#include <map>
#include <vector>
#include <tuple>

#include "zipcode.h"
#include "filereader.h"

/**
 * @brief The Buffer class reads zip code data from a file and processes it into a usable format.
 */
class Buffer {
    std::vector<ZipCodeData> zipcodes;  ///< Vector to store all zip code data.
    FileReader reader;  ///< FileReader object to handle file operations.
    
    /**
     * @brief Tokenizes a line of CSV data into individual zip code components.
     * 
     * @param line The input string representing a single line of CSV data.
     * @return A tuple containing the zip code, place name, state, county, latitude, and longitude.
     */
    std::tuple<int, std::string, std::string, std::string, float, float> tokenize_line(const std::string&);

    /**
     * @brief Populates the zipcodes vector with data parsed from the file.
     */
    void populate_zipcodes();

public:
    /**
     * @brief Constructs a Buffer object that reads data from the specified file.
     * 
     * @param file The path to the input CSV file.
     */
    Buffer(const std::string&);

    /**
     * @brief Returns the vector containing all zip code data.
     * 
     * @return A vector of ZipCodeData objects.
     */
    std::vector<ZipCodeData> get_zipcodes();
};

#endif // BUFFER_H
