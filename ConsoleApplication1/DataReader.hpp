#ifndef DataReader_hpp
#define DataReader_hpp

#include <string>
#include <fstream>
#include <vector>

class DataReader {
public:
	DataReader();
	~DataReader();
	DataReader(const std::string& inputFileName, const std::string& inputDic);

	std::vector<std::string> dictionary;
	std::vector<std::string> userWords;
	

private:
	void readDic(); //read the inputfile
	void readUserText();
	void readUserSeparator(const std::string& inputLine);
	bool isAlphabet(const char& inputChar);
	bool isLower(const char& inputChar) const;
	std::string lowerCase(const std::string& inputString) const;

	std::string userTextFileName_;
	std::string dicFileName_;
	std::string line_;
};
#include "DataReader.cpp"
#endif