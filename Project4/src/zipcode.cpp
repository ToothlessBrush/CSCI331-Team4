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
    outputstream << zipcode.zip_code << ",";
    outputstream << zipcode.place_name << ",";
    outputstream << zipcode.state << ",";
    outputstream << zipcode.county << ",";
    outputstream << zipcode.latitude << ", " << zipcode.longitude << std::endl;

    return outputstream;
}
