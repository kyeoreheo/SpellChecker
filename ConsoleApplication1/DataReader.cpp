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
    if (file.is_open()) {
        while (getline(file, line_)) {
            userText.push_back(line_);
        }
        file.close();
    }
}

//create vector that contains all player-input strings except spaces and enters
void DataReader::readUserSeparator(const std::string inputLine) {
    std::string temp = "";
    int currentLine = 0;
    while (currentLine < inputLine.size()) {
        if (inputLine[currentLine] != ' ' && inputLine[currentLine] != '\n') {
            temp += inputLine[currentLine];
            currentLine++;
        }else {
            userWords.push_back(temp);
            temp = "";
            currentLine++;
        }
    }
    userWords.push_back(temp);
}