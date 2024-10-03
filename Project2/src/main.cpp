#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

#include "zipcode.h"
#include "filereader.h"
#include "buffer.h"

std::map<std::string, std::tuple<int, int, int, int>> parse_data(std::vector<ZipCodeData> records)
{
    // create map key is state, tuple is Easternmost (least longitude), Westernmost (most longitude), Northernmost (most latitiude), Southernmost (least latitude)
    std::map<std::string, std::tuple<int, int, int, int>> data;
    std::map<std::string, std::tuple<float, float, float, float>> data_locations; // key is state, tuple is Easternmost (least longitude), Westernmost (most longitude), Northernmost (most latitiude), Southernmost (least latitude)

    for (const ZipCodeData &entry : records)
    {
        if (data.find(entry.state) == data.end())
        {
            // if state doesnt exist in map, add it
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
            else if (entry.latitude > north)
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

void print_data(std::map<std::string, std::tuple<int, int, int, int>> data)
{
    std::cout << std::left << std::setw(8) << "State" << std::setw(15) << "East" << std::setw(15) << "West" << std::setw(15) << "North" << std::setw(15) << "South" << std::endl;
    for (const auto &entry : data)
    {
        std::cout << std::left << std::setw(8) << entry.first << std::setw(15) << std::get<0>(entry.second) << std::setw(15) << std::get<1>(entry.second) << std::setw(15) << std::get<2>(entry.second) << std::setw(15) << std::get<3>(entry.second) << std::endl;
    }
}

int main()
{
    std::string file_name = "us_postal_codes_csv.csv";
    Buffer buffer(file_name);
    std::map<std::string, std::tuple<int, int, int, int>> data = parse_data(buffer.get_zipcodes());
    print_data(data);
}