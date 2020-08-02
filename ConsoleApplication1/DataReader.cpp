#include "DataReader.hpp"

DataReader::DataReader() {
    userTextFileName_ = "";
    line_ = "";
}

DataReader::~DataReader() {
    userTextFileName_ = "";
    line_ = "";
}

DataReader::DataReader(const std::string& inputFileName, const std::string& inputDic) {
    userTextFileName_ = inputFileName;
    dicFileName_ = inputDic;
    line_ = "";
    readDic();
    readUserText();
}

//read file and create vector of strings
void DataReader::readDic() {
    std::ifstream file(dicFileName_);
    if (file.is_open()) {
        while (getline(file, line_)) {
            dic.push_back(line_);
        }
        file.close();
    }
}

void DataReader::readUserText() {
    std::ifstream file(userTextFileName_);
    std::vector<std::string> userText;
    if (file.is_open()) {
        while (getline(file, line_)) {
            readUserSeparator(line_);
        }
        file.close();
    }
}

bool DataReader::isAlphabet(const char& inputChar) {
    return (inputChar > 64 && inputChar < 91) || (inputChar > 96 && inputChar < 123);
}

bool DataReader::isLower(char& inputChar) {
    return (inputChar > 96 && inputChar < 123);
}

void DataReader::lowerCase(const std::string& inputString) const{
    std::string result = "";
    for (int i = 0; i < inputString.size(); i++) {
        char currentChar = inputString[i];
        if (isLower(currentChar)) {

        }
    }
}

//create vector that contains all player-input strings except spaces and enters
void DataReader::readUserSeparator(const std::string& inputLine) {
    std::string temp = "";
    for (int i = 0; i < inputLine.size(); i++) {
        char currentChar = inputLine[i];
        if (isAlphabet(currentChar)) {
            temp += inputLine[i];
        }
        else if (temp.size() > 0) {
            userWords.push_back(lowerCase(temp));
            temp = "";
        }
    }
    if (temp.size() > 0) {
        userWords.push_back(temp);
    }

}