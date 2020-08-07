#ifndef SpellChecker_hpp
#define SpellChecker_hpp
#include <string>
#include <vector>

class SpellChecker
{
public:
    SpellChecker();
    SpellChecker(const std::vector<std::string>& inputDictionary, std::vector<std::string>& userInput);
    ~SpellChecker();


private:
    std::vector<std::string> dictionary_;
    std::vector<std::string> userInputWords_;
};

#endif /* SpellCheck_hpp */
