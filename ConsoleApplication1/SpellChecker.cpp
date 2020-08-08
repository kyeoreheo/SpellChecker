#include "SpellChecker.hpp"

SpellChecker::SpellChecker() {}

SpellChecker::~SpellChecker() {
	dictionary_.clear();
	userInputWords_.clear();
}

SpellChecker::SpellChecker(const std::vector<std::string>& inputDictionary, std::vector<std::string>& userInput) {
	dictionary_ = inputDictionary;
	userInputWords_ = userInput;
}

void SpellChecker::checkSpelling() {
	for (int i = 0; i < userInputWords_.size(); i++) {
		bool isInDictionary = false;
		for (int j = 0; j < dictionary_.size(); j++) {
			if (userInputWords_[i] == dictionary_[j] || userInputWords_[i] == "i") {
				isInDictionary = true;
			}
		}
		
		if (isInDictionary) {
			std::cout << "Found: " << userInputWords_[i] << std::endl;
		}
		else
		{
			std::cout << "Not Found: " << userInputWords_[i] << std::endl;
		}
	}
}