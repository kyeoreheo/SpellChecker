#include "SpellChecker.hpp"

SpellChecker::SpellChecker() {}

SpellChecker::~SpellChecker() {
	dictionary_.clear();
	userInputWords_.clear();
}

SpellChecker::SpellChecker(const std::vector<std::string>& inputDictionary, std::vector<std::string>& userInput) {
	dictionary_ = inputDictionary;
	userInputWords_ = userInput;
	checkSpelling();
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
		
		if (!isInDictionary) {
			insertion(userInputWords_[i]);
			deletion(userInputWords_[i]);
			swap(userInputWords_[i]);
			replace(userInputWords_[i]);
		}
	}
}

void SpellChecker::insertion(const std::string& currentIncorrectWord) {
	for (int wordPos = 0; wordPos <= currentIncorrectWord.size(); wordPos++) {
		for (int c = 97; c < 123; c++) {
			std::string charToString(1, c);
			std::string currentWord = currentIncorrectWord;
			currentWord.insert(wordPos, charToString);
			for (int i = 0; i < dictionary_.size(); i++) {
				if (currentWord == dictionary_[i]) {
					fixedWords_.push_back(currentWord);
					break;
				}
			}
		}
	}
}

void SpellChecker::deletion(const std::string& currentIncorrectWord) {
	for (int wordPos = 0; wordPos < currentIncorrectWord.size(); wordPos++) {
		std::string currentWord = currentIncorrectWord;
		currentWord.erase(currentWord.begin() + wordPos);
		for (int i = 0; i < dictionary_.size(); i++) {
			if (currentWord == dictionary_[i]) {
				fixedWords_.push_back(currentWord);
				break;
			}
		}
	}
}

void SpellChecker::swap(const std::string& currentIncorrectWord) {
	for (int currentWordPos = 0; currentWordPos < currentIncorrectWord.size()-1; currentWordPos++) {
		for (int i = currentWordPos; i < currentIncorrectWord.size()-1; i++) {
			
			std::string currentWord = currentIncorrectWord;

			int nextWordPos = i + 1;
			
			char currentChar = currentWord[currentWordPos];
			char secondChar = currentWord[nextWordPos];

			currentWord[currentWordPos] = secondChar;
			currentWord[nextWordPos] = currentChar;

			for (int i = 0; i < dictionary_.size(); i++) {
				if (currentWord == dictionary_[i]) {
					fixedWords_.push_back(currentWord);
					break;
				}
			}
		}
	}
}

void SpellChecker::replace(const std::string& currentIncorrectWord) {
	for (int wordPos = 0; wordPos < currentIncorrectWord.size(); wordPos++) {
		for (int c = 97; c < 123; c++) {
			std::string currentWord = currentIncorrectWord;
			currentWord[wordPos] = c;

			for (int i = 0; i < dictionary_.size(); i++) {
				if (currentWord == dictionary_[i]) {
					fixedWords_.push_back(currentWord);
					break;
				}
			}
		}
	}
}