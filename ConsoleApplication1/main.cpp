#include <iostream>
#include "SpellChecker.hpp"
#include "DataReader.hpp"

using namespace std;

int main()
{
    std::string strDictionary = "dictionary.txt";
    std::string strText = "Check_it2.txt";

    DataReader myDataReader(strText, strDictionary);
    /*cout << myDataReader.dic.size() << endl;

    for (int i = 0; i < myDataReader.userWords.size(); i++) {
        cout << myDataReader.userWords[i] << endl;
    }*/

    SpellChecker mySpellChecker(myDataReader.dictionary, myDataReader.userWords);
/*    for (int i = 0; i < mySpellChecker.fixedWords_.size(); i++) {
        cout << mySpellChecker.fixedWords_[i] << endl;
    }*/
    //mySpellChecker.checkSpelling();
    //mySpellChecker.insertion();
    //mySpellChecker.deletion();
    //mySpellChecker.swap();
    //mySpellChecker.replace();

    return 0;
}
