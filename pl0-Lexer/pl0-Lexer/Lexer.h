#pragma once
#include "Token.h"
#include "Number.h"
#include "Symbol.h"
#include "Word.h"
#include <vector>
#include <fstream>

#include <cstdio>
#include <cctype>

class Lexer {
public:
    Lexer();
    Lexer(std::string);
    ~Lexer();

    int lineno();
    void addlineno();

    void Tokenizer();

    void Print();
    std::string TokensToString();
private:
    Word* getword(std::string);
    Number* getnumber(std::string);
    Symbol* getsymbol(std::string);
    bool isseperator(char);
    bool iswordnumber(char);

    std::fstream in;
    std::vector<Token*> tokens;
    int lineno_ = 1;
};

Lexer::Lexer() {
}

inline Lexer::Lexer(std::string filename)
    : lineno_(1) {
    in.open(filename.c_str());
    if (!in) {
        printf("Error while opening file %s\n", filename.c_str());
        exit(0);
    }
    else {
        printf("File opened.\n");
    }
}

Lexer::~Lexer() {
    for (auto token : tokens)
        delete token;
    in.close();
}

inline int Lexer::lineno() {
    return lineno_;
}

inline void Lexer::addlineno() {
    ++lineno_;
}

inline void Lexer::Tokenizer() {
    Token* token = nullptr;
    char nextchar;

    while (in.get(nextchar)) {
        if (nextchar == '\n') {
            addlineno();
            continue;
        }
        else if (isspace(nextchar)) {
            continue;
        }
        in.putback(nextchar);
        std::string name;
        in >> name;
        if (iswordnumber(nextchar)) {
            if (isseperator(name.back())) {
                in.putback(name.back());
                name.pop_back();
            }
            if (isdigit(nextchar)) {
                token = getnumber(name);
            }
            else {
                token = getword(name);
            }
        }
        else {
            token = getsymbol(name);
        }
        tokens.push_back(token);
    }
}

inline std::string Lexer::TokensToString() {
    std::string content;
    for (auto token : tokens) {
        content += token->ContentToString();
    }
    return content;
}

inline Word* Lexer::getword(std::string name) {
    return new Word(name, lineno());
}

inline Number* Lexer::getnumber(std::string name) {
    return new Number(name, lineno());
}

inline Symbol* Lexer::getsymbol(std::string name) {
    return new Symbol(name, lineno());
}

inline bool Lexer::isseperator(char symbol) {
    if (symbol == ';' || symbol == ',')
        return true;
    return false;
}

inline bool Lexer::iswordnumber(char ch) {
    if (isalnum(ch) || ch == '_')
        return true;
    return false;
}
