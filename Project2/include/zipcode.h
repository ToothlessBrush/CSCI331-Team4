/**
 * @file zipcode.h
 */
#ifndef ZIP_CODE_H
#define ZIP_CODE_H

#include <string>
#include <tuple>

/**
 * @brief The ZipCodeData struct holds data for a single zip code, including its coordinates and place information.
 */
struct ZipCodeData
{
    int zip_code;             ///< The zip code.
    std::string place_name;   ///< The name of the place corresponding to the zip code.
    std::string state;        ///< The state (two-character abbreviation).
    std::string county;       ///< The county of the place.
    float latitude;           ///< The latitude coordinate.
    float longitude;          ///< The longitude coordinate.

    /**
     * @brief Constructs a ZipCodeData object from a tuple containing zip code details.
     * 
     * @param tuple A tuple containing zip code, place name, state, county, latitude, and longitude.
     */
    ZipCodeData(std::tuple<int, std::string, std::string, std::string, float, float>);
    
    /**
     * @brief Overloads the << operator to print the ZipCodeData to an output stream.
     * 
     * @param outputstream The output stream.
     * @param zipcode The ZipCodeData object to be printed.
     * @return The output stream after the zip code data is written.
     */
    friend std::ostream& operator<<(std::ostream&, const ZipCodeData&);
};

#endif // ZIP_CODE_H
