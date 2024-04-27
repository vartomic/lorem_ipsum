#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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

void wordCount2(char* arr) {

    std::vector<std::string> words;
    char delimiters[] = " ,.;\n";
    char* token = NULL;
    char* ptr = NULL;

    token = strtok_s(arr, delimiters, &ptr);

    while (token != NULL) {
        words.push_back(std::string(token));
        token = strtok_s(NULL, delimiters, &ptr);
    }

    std::sort(words.begin(), words.end());

    int count = 1;

    for (int i = 0; i < words.size()-1; i++) {
        auto j = i + 1;

        if (words[i] == words[j]) {
            count++;
        }
        else {
            std::cout << words[i] << ' ' << count << std::endl;
            count = 1;
        }
    }
}

void wordCount3(char* arr) {

    std::map<std::string, int> mp;

    std::vector<std::string> words;
    char delimiters[] = " ,.;\n";
    char* token = NULL;
    char* ptr = NULL;

    token = strtok_s(arr, delimiters, &ptr);

    while (token != NULL) {
        words.push_back(std::string(token));
        token = strtok_s(NULL, delimiters, &ptr);
    }

    for (auto& word : words) {
        if (mp.count(word)) {
            mp[word]++;
        }
        else {
            mp[word] = 1;
        }
    }
    for (auto& elem : mp) {
        std::cout << elem.first << ' ' << elem.second << std::endl;
    }
}

int main() {
    //wordCount(text);
    //wordCount2(text);
    wordCount3(text);
}


