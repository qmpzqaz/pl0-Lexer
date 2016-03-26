#pragma once
#include "Token.h"
#include <string>
#include <sstream>
#include <regex>

#include <cstdio>

class Number : public Token {
public:
    Number();
    Number(std::string, int);
    ~Number();

    int value();
    void set_value(int);

    std::string ContentToString() override;
private:
    static Tag NumberTag(std::string);

    int value_ = 0;
};

Number::Number() {
}

inline Number::Number(std::string name, int lineno)
    :Token(name, NumberTag(name), lineno) {
    int value = 0;
    if (tag() != Tags[BadToken]) {
        std::istringstream(name) >> value;
    }
    set_value(value);
}

Number::~Number() {
}

inline std::string Number::ContentToString() {
    char content[100];
    sprintf(content, "%-12s %s\n", name().c_str(), TagToString(tag()).c_str());
    return std::string(content);
}

inline int Number::value() {
    return value_;
}

inline void Number::set_value(int value) {
    value_ = value;
}

inline Tag Number::NumberTag(std::string name) {
    if (std::regex_match(name, std::regex("[0-9]+"))) {
        return Tags[NumericalValue];
    }
    return Tags[BadToken];
}
