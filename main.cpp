//Kyeore Heo 
//91kyoheo@gmail.com
#include <iostream>
#include "SpellChecker.hpp"

int main()
{
    std::string strDictionary = "dictionary.txt";
    std::string strText = "Check_it2.txt";
    SpellChecker mySpellChecker(strDictionary);
    mySpellChecker.CheckWithVector(strText);
    return 0;
}
