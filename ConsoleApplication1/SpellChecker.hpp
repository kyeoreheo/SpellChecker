#ifndef SpellChecker_hpp
#define SpellChecker_hpp
#include <iostream>
#include <string>
#include <vector>

class SpellChecker
{
public:
    SpellChecker();
    SpellChecker(const std::vector<std::string>& inputDictionary, std::vector<std::string>& userInput);
    ~SpellChecker();

    void checkSpelling();
    void insertion();
    void deletion();
    void swap();
    void replace();
    //void suggestion();
    std::vector<std::string> fixedWords_;

private:
    std::vector<std::string> dictionary_;
    std::vector<std::string> userInputWords_;
    std::vector<std::string> incorrectWords_;
    
};
#include "SpellChecker.cpp"
#endif /* SpellCheck_hpp */
