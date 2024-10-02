#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <fstream>
#include <vector>

class FileReader 
{
    std::vector<std::string> lines;
    std::ifstream file;
    void populate_lines();

public:
    FileReader(const std::string&);
    std::vector<std::string> get_lines();

    friend std::ostream& operator<<(std::ostream&, const FileReader&);

};

#endif // FILE_READER_H
