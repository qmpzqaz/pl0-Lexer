#pragma once
#include "Tag.h"
#include <string>

class Token {
public:
    Token();
    Token(std::string, Tag, int);
    virtual ~Token();

    Tag tag();
    int lineno();
    void set_tag(Tag);
    std::string name();

    virtual std::string ContentToString();
private:
    std::string name_;
    Tag tag_;
    int lineno_ = 1;
};

Token::Token() {
}

inline Token::Token(std::string name, Tag tag, int lineno)
    :name_(name), tag_(tag), lineno_(lineno) {
}

Token::~Token() {
}

inline Tag Token::tag() {
    return tag_;
}

inline int Token::lineno() {
    return lineno_;
}

inline void Token::set_tag(Tag tag) {
    tag_ = tag;
}

inline std::string Token::name() {
    return name_;
}

inline std::string Token::ContentToString() {
    return std::string();
}
