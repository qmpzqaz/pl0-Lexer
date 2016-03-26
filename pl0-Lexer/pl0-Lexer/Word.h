#pragma once
#include "Token.h"
#include <regex>

#include <cstdio>

class Word :public Token {
public:
    Word();
    Word(std::string, int);
    ~Word();

    std::string ContentToString() override;

private:
    static Tag KeywordTag(std::string);
};

Word::Word() {
}

inline Word::Word(std::string name, int lineno)
    : Token(name, KeywordTag(name), lineno) {
}

Word::~Word() {
}

inline std::string Word::ContentToString() {
    char content[100];
    if (tag() == Tags[Identifier])
        sprintf(content, "%-12s %s\n", name().c_str(), TagToString(tag()).c_str());
    else
        sprintf(content, "%-12s Keyword %s\n", name().c_str(), TagToString(tag()).c_str());
    return std::string(content);
}

inline Tag Word::KeywordTag(std::string name) {
    std::string lowercasename;
    for each (auto ch in name) {
        char c = tolower(ch);
        lowercasename.push_back(c);
    }
    
    for (int i = 0; i != NumberOfKeyword; ++i) {
        if (KeywordTable[i] == lowercasename)
            return Tags[KeywordStart + i];
    }
    if (std::regex_match(name, std::regex("[a-zA-Z_][a-zA-Z0-9_]{0,31}"))) {
        return Tags[Identifier];
    }
    return Tags[BadToken];
}