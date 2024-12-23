#include <numeric>
#include "Func.h"

std::string DropWordsWithNoUniqueChars(const std::string &str) {
    std::stringstream ss(str);
    std::vector<std::string> words;
    std::string word;

    while (ss >> word) {
        words.push_back(word);
    }

    if(words.empty()) return "";

    std::string last_word = words.back();
    std::stringstream res;

    for (const auto &word: words) {
        std::set<char> char_set(word.begin(), word.end());
        if (char_set.size() == word.size()) {
            res << word << " ";
        }
    }

    std::string string = res.str();
    return ClearSpaces(string);
}

std::string MakeStringWithNoLastWord(const std::string &str) {
    std::stringstream ss(str);
    std::vector<std::string> words;
    std::string word;

    while (ss >> word) {
        words.push_back(word);
    }

    if(words.empty()) return "";

    std::string last_word = words.back();
    std::stringstream res;

    for (const auto &word: words) {
        if (word != last_word) {
            res << word << " ";
        }
    }

    std::string string = res.str();
    return ClearSpaces(string);
}

std::string ClearSpaces(const std::string &str) {
    std::stringstream ss(str);
    std::stringstream res;
    std::string word;

    for (int i = 0; ss >> word; ++i) {
        if (i != 0) res << " ";
        res << word;
    }

    return res.str();
}