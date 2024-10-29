#ifndef ZIP_CODE_MAPPING_H
#define ZIP_CODE_MAPPING_H

#include "mapping.h"
#include "zipcode.h"
#include <string>
#include <vector>

class ZipCodeMapping {
    Mapping<std::string> zip_code_mapping;
public:
    ZipCodeMapping(const std::vector<ZipCodeData>&);
    bool has_key(const std::string&);
    void write_to_stream(std::ostream&, const std::string&);
};

#endif // ZIP_CODE_MAPPING_H
