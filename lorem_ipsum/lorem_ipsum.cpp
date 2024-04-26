#include <iostream>
#include <vector>
#include <algorithm>
#include "text.h"
#include "separateUniqueWords.h"

void wordCount(char* arr) {

    std::vector<std::string> words;
    char delimiters[] = " ,.;\n";
    char* token = NULL;
    char* ptr = NULL;

    token = strtok_s(arr, delimiters, &ptr);

    while (token != NULL) {
        words.push_back(std::string(token));
        token = strtok_s(NULL, delimiters, &ptr);        
    }

    std::vector<std::string> uniqueWords = separateUniqueWords(words);

    int count = 0;

    for (int i = 0; i < uniqueWords.size(); i++) {
        count = 0;
        for (int j = 0; j < words.size(); j++) {
            if (words[j] == uniqueWords[i]) {
                count++;
            }           
        }
        std::cout << uniqueWords[i] << ' ' << count << std::endl;
    }
}

int main() {
    wordCount(text);
}


