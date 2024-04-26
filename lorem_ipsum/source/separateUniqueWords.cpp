#include "separateUniqueWords.h"

std::vector<std::string> separateUniqueWords(std::vector<std::string> words) {

	std::vector<std::string> uniqueWords;

	for (int i = 0; i < words.size(); i++) {
		bool isUnique = true;

		for (int j = 0; j < uniqueWords.size(); j++) {
			if (words[i] == uniqueWords[j]) {
				isUnique = false;
			}
		}
		if (isUnique == true) {
			uniqueWords.push_back(words[i]);
		}
	}
	return uniqueWords;
}