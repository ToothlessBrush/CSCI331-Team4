/**
 * @file filereader.h
 */
#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <fstream>
#include <vector>

/**
 * @brief The FileReader class handles reading lines from a file.
 */
class FileReader 
{
    std::vector<std::string> lines;  ///< Vector to store lines read from the file.
    std::ifstream file;  ///< Input file stream.
    
    /**
     * @brief Populates the lines vector by reading each line from the file.
     */
    void populate_lines();

public:
    /**
     * @brief Constructs a FileReader object and opens the specified file.
     * 
     * @param input_file The path to the input file.
     * @throws std::runtime_error If the file cannot be opened.
     */
    FileReader(const std::string&);

    /**
     * @brief Returns the lines read from the file.
     * 
     * @return A vector of strings representing each line in the file.
     */
    std::vector<std::string> get_lines();

    /**
     * @brief Overloads the << operator to print all lines of the file to an output stream.
     * 
     * @param outputstream The output stream.
     * @param reader The FileReader object containing the lines to print.
     * @return The output stream after the lines are written.
     */
    friend std::ostream& operator<<(std::ostream&, const FileReader&);
};

#endif // FILE_READER_H
