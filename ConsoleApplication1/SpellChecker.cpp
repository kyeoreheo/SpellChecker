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
				answer_ += userInputWords_[i];
				answer_ += " ";
				break;
			}
		}
		
		if (!isInDictionary) {
			answer_ += userInputWords_[i];
			answer_ += "(";
			insertion(userInputWords_[i]);
			if(hasFoundAns_){
				answer_ += ", ";
			}
			deletion(userInputWords_[i]);
			if(hasFoundAns_){
				answer_ += ", ";
			}
			swap(userInputWords_[i]);
			if(hasFoundAns_){
				answer_ += ", ";
			}
			replace(userInputWords_[i]);
			if(answer_[answer_.size() - 1] == ' '){
				answer_.erase(answer_.begin() + answer_.size() - 2, answer_.begin() + answer_.size());
			}
			answer_ += ") ";
		}
	}
}

void SpellChecker::insertion(const std::string& currentIncorrectWord) {
	std::string tempAns = "";
	hasFoundAns_ = false;
	for (int wordPos = 0; wordPos <= currentIncorrectWord.size(); wordPos++) {
		for (int c = 97; c < 123; c++) {
			std::string charToString(1, c);
			std::string currentWord = currentIncorrectWord;
			currentWord.insert(wordPos, charToString);
			for (int i = 0; i < dictionary_.size(); i++) {
				if (currentWord == dictionary_[i]) {
					hasFoundAns_ = true;
					tempAns += currentWord;
					tempAns += ", ";
					break;
				}
			}
		}
	}
	if(tempAns.size() > 0){
		if(tempAns[tempAns.size() - 1] == ' '){
			tempAns.erase(tempAns.begin() + tempAns.size() - 2, tempAns.begin() + tempAns.size());
		}
		answer_ += tempAns;
	}

}

void SpellChecker::deletion(const std::string& currentIncorrectWord) {
	std::string tempAns = "";
	hasFoundAns_ = false;
	for (int wordPos = 0; wordPos < currentIncorrectWord.size(); wordPos++) {
		std::string currentWord = currentIncorrectWord;
		currentWord.erase(currentWord.begin() + wordPos);
		for (int i = 0; i < dictionary_.size(); i++) {
			if (currentWord == dictionary_[i]) {
				hasFoundAns_ = true;
				tempAns += currentWord;
				tempAns += ", ";
				break;
			}
		}
	}
	if(tempAns.size() > 0){
		if(tempAns[tempAns.size() - 1] == ' '){
			tempAns.erase(tempAns.begin() + tempAns.size() - 2, tempAns.begin() + tempAns.size());
		}
		answer_ += tempAns;
	}
}

void SpellChecker::swap(const std::string& currentIncorrectWord) {
	std::string tempAns = "";
	hasFoundAns_ = false;
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
					hasFoundAns_ = true;
					tempAns += currentWord;
					tempAns += ", ";
					break;
				}
			}
		}
	}
	if(tempAns.size() > 0){
		if(tempAns[tempAns.size() - 1] == ' '){
			tempAns.erase(tempAns.begin() + tempAns.size() - 2, tempAns.begin() + tempAns.size());
		}
		answer_ += tempAns;
	}
}

void SpellChecker::replace(const std::string& currentIncorrectWord) {
	std::string tempAns = "";
	hasFoundAns_ = false;
	for (int wordPos = 0; wordPos < currentIncorrectWord.size(); wordPos++) {
		for (int c = 97; c < 123; c++) {
			std::string currentWord = currentIncorrectWord;
			currentWord[wordPos] = c;

			for (int i = 0; i < dictionary_.size(); i++) {
				if (currentWord == dictionary_[i]) {
					hasFoundAns_ = true;
					tempAns += currentWord;
					tempAns += ", ";
					break;
				}
			}
		}
	}
	if(tempAns.size() > 0){
		if(tempAns[tempAns.size() - 1] == ' '){
			tempAns.erase(tempAns.begin() + tempAns.size() - 2, tempAns.begin() + tempAns.size());
		}
		answer_ += tempAns;
	}
}