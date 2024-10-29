/**
 * @file zipcode.cpp
 */
#include <iostream>
#include "zipcode.h"

ZipCodeData::ZipCodeData(std::tuple<std::string, std::string, std::string, std::string, float, float> tuple)
{
    std::tie(this->zip_code, this->place_name, this->state, this->county, this->latitude, this->longitude) = tuple;
}

std::ostream& operator<<(std::ostream& outputstream, const ZipCodeData& zipcode) {
    outputstream << "Zip Code: " << zipcode.zip_code << std::endl;
    outputstream << "Place Name: " << zipcode.place_name << std::endl;
    outputstream << "State: " << zipcode.state << std::endl;
    outputstream << "County: " << zipcode.county << std::endl;
    outputstream << "Latitude and Longitude: " << zipcode.latitude << ", " << zipcode.longitude << std::endl;

    return outputstream;
}
