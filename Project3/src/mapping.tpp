#include "mapping.h"

template <typename T>
void Mapping<T>::add_entry(const T& key, const ZipCodeData& zipcode_data) {
    this->mapping[key].push_back(zipcode_data);
}

template <typename T>
bool Mapping<T>::key_exists(const T& key) {
    return this->mapping.find(key) != this->mapping.end();
}

template <typename T>
std::vector<ZipCodeData> Mapping<T>::get_by_key(const T& key) {
    return this->mapping[key];
}

template<typename T>
void Mapping<T>::write_to_os(std::ostream& os, const T& key) {
    std::vector<ZipCodeData> data = this->get_by_key(key);

    for (const ZipCodeData& entry : data) {
        os << entry;
    }
}
