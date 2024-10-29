#ifndef MAPPING_H
#define MAPPING_H

#include <vector>
#include <iostream>
#include <map>
#include "zipcode.h"

template <typename T>
class Mapping {
    std::map<T, std::vector<ZipCodeData>> mapping;
public:
    void add_entry(const T&, const ZipCodeData&);
    bool key_exists(const T&);
    void write_to_os(std::ostream&, const T&);
    std::vector<ZipCodeData> get_by_key(const T&);

};

#endif // MAPPING_H
