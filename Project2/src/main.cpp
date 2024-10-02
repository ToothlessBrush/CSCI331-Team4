#include <iostream>
#include <vector>

#include "zipcode.h"
#include "filereader.h"
#include "buffer.h"

int main() {
    std::string file_name = "sample.csv";
    Buffer buffer(file_name);

    std::vector<ZipCodeData> zipcodes = buffer.get_zipcodes();

    for (int i = 0; i < zipcodes.size(); i++) {
        std::cout << zipcodes[i] << std::endl;
    }
}