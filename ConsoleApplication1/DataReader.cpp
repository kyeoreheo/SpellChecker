#include "DataReader.hpp"

DataReader::DataReader() {
    fileName_ = "";
    line_ = "";
}

DataReader::~DataReader() {
    fileName_ = "";
    line_ = "";
}

DataReader::DataReader(const std::string& inputFileName) {
    fileName_ = inputFileName;
    line_ = "";
    readFile();
}

void DataReader::readFile() {
    std::ifstream file(fileName_);
    if (file.is_open()) {
        while (getline(file, line_)) {
            dic.push_back(line_);
        }
        file.close();
    }
}