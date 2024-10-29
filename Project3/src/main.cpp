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

    std::string filepath = argv[1], zipcode = argv[2];

    std::cout << "File name: " << filepath << std::endl;
    std::cout << "Zip code: " << zipcode << std::endl;

    Buffer buffer(filepath);

    ZipCodeMapping zip_code_map(buffer.get_zipcodes());
    return 0;
}
