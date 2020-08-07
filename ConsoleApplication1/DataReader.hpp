#ifndef DataReader_hpp
#define DataReader_hpp

#include <string>
#include <fstream>
#include <vector>

class DataReader {
public:
	DataReader();
	~DataReader();
	DataReader(const std::string& inputFileName);
	std::vector<std::string> dic;

private:
	void readFile(); //read the inputfile and generate pokemonData and firendsData

	std::string fileName_;
	std::string line_;
};

#include "DataReader.cpp"
#endif