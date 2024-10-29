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
    this->zip_code_mapping.write_to_os(os, zipcode);
}
