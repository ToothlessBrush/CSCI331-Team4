/**
 * @file filereader.cpp
 */
#include "filereader.h"

FileReader::FileReader(const std::string& input_file) 
{
    this->file.open(input_file.c_str());

    if (!this->file.is_open()) {
        throw std::runtime_error("Failed to open the file");
    }

    this->populate_lines();
}

void FileReader::populate_lines()
{
    std::string line;
    while (std::getline(this->file, line)) {
        this->lines.push_back(line);
    }
}

std::vector<std::string> FileReader::get_lines() {
    return lines;
}

std::ostream& operator<<(std::ostream& outputstream, const FileReader& reader) {
    for (int i = 0; i < reader.lines.size(); i++) {
       outputstream << reader.lines[i] << std::endl;
    }

    return outputstream;
}
