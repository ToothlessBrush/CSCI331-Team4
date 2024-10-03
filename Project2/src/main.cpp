/**
 * @file main.cpp
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

#include "zipcode.h"
#include "filereader.h"
#include "buffer.h"

/**
 * @brief Parses a vector of ZipCodeData records to find the Easternmost, Westernmost, Northernmost, and Southernmost zip codes for each state.
 *
 * @param records A vector of ZipCodeData containing zip code information including latitude and longitude.
 * @return A map where the key is the state (two-letter string), and the value is a tuple of integers representing:
 *         - Easternmost zip code (least longitude)
 *         - Westernmost zip code (most longitude)
 *         - Northernmost zip code (most latitude)
 *         - Southernmost zip code (least latitude)
 */
std::map<std::string, std::tuple<int, int, int, int>> parse_data(const std::vector<ZipCodeData> &records)
{
    // create map key is state, tuple is Easternmost (least longitude), Westernmost (most longitude), Northernmost (most latitude), Southernmost (least latitude)
    std::map<std::string, std::tuple<int, int, int, int>> data;
    std::map<std::string, std::tuple<float, float, float, float>> data_locations; // key is state, tuple for coordinates

    for (const ZipCodeData &entry : records)
    {
        if (data.find(entry.state) == data.end())
        {
            // if state doesn't exist in the map, add it
            data[entry.state] = std::make_tuple(entry.zip_code, entry.zip_code, entry.zip_code, entry.zip_code);             // store the zip code of the first entry
            data_locations[entry.state] = std::make_tuple(entry.longitude, entry.longitude, entry.latitude, entry.latitude); // store the coordinates of the first entry
        }
        else
        {
            // grab the current tuple to compare with the new entry
            std::tuple<float, float, float, float> current = data_locations[entry.state];
            float east = std::get<0>(current);
            float west = std::get<1>(current);
            float north = std::get<2>(current);
            float south = std::get<3>(current);

            int east_zip_code = std::get<0>(data[entry.state]);
            int west_zip_code = std::get<1>(data[entry.state]);
            int north_zip_code = std::get<2>(data[entry.state]);
            int south_zip_code = std::get<3>(data[entry.state]);

            int zip_code = entry.zip_code;

            // check if the new entry is more eastern than the current easternmost
            if (entry.longitude < east)
            {
                east = entry.longitude;
                east_zip_code = zip_code;
            }
            else if (entry.longitude > west)
            {
                west = entry.longitude;
                west_zip_code = zip_code;
            }

            // check if the new entry is more northern or southern than the current northernmost or southernmost (not else if since it could be both)
            if (entry.latitude > north)
            {
                north = entry.latitude;
                north_zip_code = zip_code;
            }
            else if (entry.latitude < south)
            {
                south = entry.latitude;
                south_zip_code = zip_code;
            }

            data[entry.state] = std::make_tuple(east_zip_code, west_zip_code, north_zip_code, south_zip_code);
            data_locations[entry.state] = std::make_tuple(east, west, north, south);
        }
    }

    return data;
}

/**
 * @brief Prints the parsed data of each state with the respective Easternmost, Westernmost, Northernmost, and Southernmost zip codes.
 *
 * @param data A map where the key is the state (string) and the value is a tuple of zip codes (int) for East, West, North, and South extremes.
 */
void print_data(const std::map<std::string, std::tuple<int, int, int, int>> &data)
{
    std::cout << std::left << std::setw(8) << "State" << std::setw(15) << "East" << std::setw(15) << "West" << std::setw(15) << "North" << std::setw(15) << "South" << std::endl;
    for (const auto &entry : data)
    {
        std::cout << std::left << std::setw(8) << entry.first << std::setw(15) << std::get<0>(entry.second) << std::setw(15) << std::get<1>(entry.second) << std::setw(15) << std::get<2>(entry.second) << std::setw(15) << std::get<3>(entry.second) << std::endl;
    }
}

/**
 * @brief Main function that reads zip code data from a CSV file, parses it, and prints the extreme zip codes (East, West, North, South) for each state.
 *
 * @return int Returns 0 if the program executes successfully.
 */
int main()
{
    std::string file_name = "us_postal_codes_csv.csv";
    Buffer buffer(file_name);
    std::map<std::string, std::tuple<int, int, int, int>> data = parse_data(buffer.get_zipcodes());
    print_data(data);
    return 0;
}
