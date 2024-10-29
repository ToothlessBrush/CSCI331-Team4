#include "zipcodemapping.h"

ZipCodeMapping::ZipCodeMapping(const std::vector<ZipCodeData>& data) {
    for (const ZipCodeData& entry : data) {
        this->zip_code_mapping.add_entry(entry.zip_code, entry);
    }
}

bool ZipCodeMapping::has_key(const std::string& zipcode) {
    return this->zip_code_mapping.key_exists(zipcode);
}

void ZipCodeMapping::write_to_stream(std::ostream& os, const std::string& zipcode) {
    os << "Record for: " << zipcode << std::endl;
    os << "-------------------------------------" << std::endl;
    os << "zip_code" << "," << "place_name" << "," << "state" << "," << "county" << "," << "latitude" << "," << "longitude" << std::endl;
    this->zip_code_mapping.write_to_os(os, zipcode);
}
