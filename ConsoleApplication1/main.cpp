#include <iostream>
#include <fstream>
#include "SpellChecker.hpp"
#include "DataReader.hpp"

using namespace std;

int main()
{
    std::string strDictionary = "dictionary.txt";
    std::string strText = "Check_it2.txt";

    DataReader myDataReader(strText, strDictionary);

    SpellChecker mySpellChecker(myDataReader.dictionary, myDataReader.userWords);

    return 0;
}
