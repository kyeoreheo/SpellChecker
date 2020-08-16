#include "SpellChecker.hpp"

SpellChecker::SpellChecker() {}

SpellChecker::~SpellChecker() {
	dictionary_.clear();
	userInputWords_.clear();
}

SpellChecker::SpellChecker(const std::vector<std::string>& inputDictionary, std::vector<std::string>& userInput) {
	dictionary_ = inputDictionary;
	userInputWords_ = userInput;
	/*checkSpelling();
	insertion();
	deletion();
	swap();
	replace();*/
	for(int i = 0; i < dictionary_.size(); i++){
		std::string currentElement = dictionary_[i];
		int lastIndex = currentElement.size()-1;
		char lastChar = currentElement[lastIndex];
		std::cout << "--------" << std::endl;
		std::cout << "Element: " << currentElement << std::endl; 
		std::cout << "Length: " << currentElement.size() << std::endl;
		std::cout << "Last Element: " << currentElement[lastIndex] << std::endl;
		std::cout << "Last Character: " << lastChar + 1 << std::endl;
		std::cout << "--------" << std::endl;
	}
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
						std::cout << "Insertion(): " << fixedWords_.size() << std::endl;
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
		for (int wordPos = 0; wordPos < incorrectWords_[wordIndex].size(); wordPos++) {
			std::string currentWord = incorrectWords_[wordIndex];
			currentWord.erase(currentWord.begin() + wordPos);
			//std::cout << "CurrentWord " << currentWord << "/" << "WordIndex " << wordIndex << "/" << "WordPos " << wordPos << "Length: " << incorrectWords_[wordIndex].size() << std::endl;
			for (int i = 0; i < dictionary_.size(); i++) {
				if (currentWord == dictionary_[i]) {
					//std::cout << currentWord << std::endl;
					fixedWords_.push_back(currentWord);
					std::cout << "Deletion(): " << fixedWords_.size() << std::endl;
					break;
				}
			}
		}
	}
}

void SpellChecker::swap() {
	for (int wrongWordIndex = 0; wrongWordIndex < incorrectWords_.size(); wrongWordIndex++) {
		for (int currentWordPos = 0; currentWordPos < incorrectWords_[wrongWordIndex].size()-1; currentWordPos++) {
			for (int i = currentWordPos; i < incorrectWords_[wrongWordIndex].size()-1; i++) {
				
				std::string currentWord = incorrectWords_[wrongWordIndex];

				int nextWordPos = i + 1;
				
				char currentChar = currentWord[currentWordPos];
				char secondChar = currentWord[nextWordPos];

				currentWord[currentWordPos] = secondChar;
				currentWord[nextWordPos] = currentChar;

				for (int i = 0; i < dictionary_.size(); i++) {
					if (currentWord == dictionary_[i]) {
						//std::cout << currentWord << std::endl;
						fixedWords_.push_back(currentWord);
						std::cout << "Swap(): " << fixedWords_.size() << std::endl;
						break;
					}
				}
			}
		}
	}
}

void SpellChecker::replace() {
	for (int wordIndex = 0; wordIndex < incorrectWords_.size(); wordIndex++) {
		for (int wordPos = 0; wordPos < incorrectWords_[wordIndex].size(); wordPos++) {
			for (int c = 97; c < 123; c++) {
				std::string currentWord = incorrectWords_[wordIndex];
				currentWord[wordPos] = c;

				for (int i = 0; i < dictionary_.size(); i++) {
					if (currentWord == dictionary_[i]) {
						//std::cout << currentWord << std::endl;
						fixedWords_.push_back(currentWord);
						std::cout << "Replace(): " << fixedWords_.size() << std::endl;
						break;
					}
				}
			}
		}
	}
}