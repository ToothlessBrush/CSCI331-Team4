/**
 * @file buffer.cpp
 */
#include "buffer.h"

#include <sstream>

Buffer::Buffer(const std::string& file) : reader(FileReader(file))
{
    this->populate_zipcodes();
}

std::tuple<std::string, std::string, std::string, std::string, float, float> Buffer::tokenize_line(const std::string& line)
{
    std::string zip_code;
    std::string place_name;
    std::string state;
    std::string county;
    float latitude;
    float longitude;

    std::stringstream stream(line);
    std::string token;

    std::getline(stream, zip_code, ',');

    std::getline(stream, place_name, ',');

    std::getline(stream, state, ',');

    std::getline(stream, county, ',');

    std::getline(stream, token, ',');
    latitude = std::stof(token);

    std::getline(stream, token, ',');
    longitude = std::stof(token);


    return std::make_tuple(zip_code, place_name, state, county, latitude, longitude);
}

void Buffer::populate_zipcodes()
{
    std::vector<std::string> data = reader.get_lines();

    for (int i = 1; i < data.size(); i++) {
        std::tuple<std::string, std::string, std::string, std::string, float, float> zipcode_data = tokenize_line(data[i]);
        this->zipcodes.push_back(ZipCodeData(zipcode_data));
    }
}

std::vector<ZipCodeData> Buffer::get_zipcodes() {
    return this->zipcodes;
}
