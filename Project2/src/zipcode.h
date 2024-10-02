#ifndef ZIP_CODE_H
#define ZIP_CODE_H

#include <string>
#include <tuple>

struct ZipCodeData
{
    int zip_code;
    std::string place_name;
    std::string state;
    std::string county;
    float latitude;
    float longitude;

    ZipCodeData(std::tuple<int, std::string, std::string, std::string, float, float>);
    
    friend std::ostream& operator<<(std::ostream&, const ZipCodeData&);
};

#endif // ZIP_CODE_H
