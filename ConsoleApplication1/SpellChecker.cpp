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