#ifndef ZIP_CODE_H
#define ZIP_CODE_H

#include <string>

struct ZipCodeData
{
    int zip_code;
    std::string place_name;
    std::string state;
    std::string county;
    float latitude;
    float longitude;
};

#endif // ZIP_CODE_H
