#include <string>
#include <map>
#include <vector>
#include <tuple>

#include "zipcode.h"
#include "filereader.h"

class Buffer {
    std::vector<ZipCodeData> zipcodes;
    FileReader reader;
    std::tuple<int, std::string, std::string, std::string, float, float> tokenize_line(const std::string&);
    void populate_zipcodes();
    
public:
    Buffer(const std::string&);

    std::vector<ZipCodeData> get_zipcodes();
};