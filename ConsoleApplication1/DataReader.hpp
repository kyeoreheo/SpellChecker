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

	std::vector<std::string> dic;
	std::vector<std::string> userWords;
	std::vector<std::string> userText;

	void readUserSeparator(const std::string inputLine);

private:
	void readDic(); //read the inputfile
	void readUserText();

	std::string userTextFileName_;
	std::string dicFileName_;
	std::string line_;
};

#endif