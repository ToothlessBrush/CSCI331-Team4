/**
 * @file main.cpp
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

#include "zipcodemapping.h"
#include "filereader.h"
#include "buffer.h"

/**
 * @brief Main function that reads zip code data from a CSV file, parses it, and prints the extreme zip codes (East, West, North, South) for each state.
 *
 * @return int Returns 0 if the program executes successfully.
 */
int main(int argc, char* argv[])
{
    if (argc < 3) {
        std::cerr << "Usage: ./a.out <filepath> -<zipcode>" << std::endl;
        return 1;
    }

    std::string filepath = argv[1];
    std::vector<std::string> zipcodes;

    for (int i = 2; i < argc; ++i) {
        if (argv[i][0] == '-' && argv[i][1] == 'Z') {
            zipcodes.emplace_back(argv[i] + 2);
        }
        else {
            std::cerr << "Invalid Zip Code Format: " << argv[i] << ". Use -Z<zipcode>" << std::endl << std::endl;
        }
    }

    Buffer buffer(filepath);

    ZipCodeMapping zip_code_map(buffer.get_zipcodes());

    for (const std::string& zipcode : zipcodes) {
        if (!zip_code_map.has_key(zipcode)) {
            std::cout << "Zip code does not exist in file" << std::endl << std::endl;
        } 
        else {
            zip_code_map.write_to_stream(std::cout, zipcode);
            std::cout << std::endl;
        }
    }

    return 0;
}
