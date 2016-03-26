#pragma once
#include "Token.h"

#include <cstdio>

class Symbol : public Token {
public:
    Symbol();
    Symbol(std::string name, int lineno);
    ~Symbol();

    std::string ContentToString() override;

    static Tag SymbolTag(std::string);
private:

};

Symbol::Symbol() {
}

inline Symbol::Symbol(std::string name, int lineno)
    : Token(name, SymbolTag(name), lineno) {
}

Symbol::~Symbol() {
}

inline std::string Symbol::ContentToString() {
    char content[100];
    sprintf(content, "%-12s %s\n", name().c_str(), TagToString(tag()).c_str());

    return std::string(content);
}

inline Tag Symbol::SymbolTag(std::string name) {
    for (int i = 0; i != NumberOfSymbol; ++i) {
        if (SymbolTable[i] == name)
            return Tags[SymbolStart + i];
    }
    return Tags[BadToken];
}
