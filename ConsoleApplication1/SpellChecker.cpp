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
				break;
			}
		}
		
		if (isInDictionary) {
			//std::cout << "Found: " << userInputWords_[i] << std::endl;
		}
		else
		{
			//std::cout << "Not Found: " << userInputWords_[i] << std::endl;
			incorrectWords_.push_back(userInputWords_[i]);
		}
	}
}

void SpellChecker::insertion() {
	for (int wordIndex = 0; wordIndex < incorrectWords_.size(); wordIndex++) {
		for (int wordPos = 0; wordPos <= incorrectWords_[wordIndex].size(); wordPos++) {
			for (int c = 97; c < 123; c++) {
				std::string charToString(1, c);
				std::string currentWord = incorrectWords_[wordIndex];
				currentWord.insert(wordPos, charToString);
				for (int i = 0; i < dictionary_.size(); i++) {
					if (currentWord == dictionary_[i]) {
						//std::cout << currentWord << std::endl;
						fixedWords_.push_back(currentWord);
						break;
					}
				}
				
				//std::cout << currentWord << std::endl;
			}
		}
	}
}

void SpellChecker::deletion() {
	for (int wordIndex = 0; wordIndex < incorrectWords_.size(); wordIndex++) {
		for (int wordPos = 0; wordPos <= incorrectWords_[wordIndex].size(); wordPos++) {
			std::string currentWord = incorrectWords_[wordIndex];
			currentWord.erase(currentWord.begin() + wordPos);
			for (int i = 0; i < dictionary_.size(); i++) {
				if (currentWord == dictionary_[i]) {
					//std::cout << currentWord << std::endl;
					fixedWords_.push_back(currentWord);
					break;
				}
			}
		}
	}
}