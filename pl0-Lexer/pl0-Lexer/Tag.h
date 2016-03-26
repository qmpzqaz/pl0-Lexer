#pragma once
#include <string>

const int MaxWordLength = 32;  // Believe it or not.

const int NumberOfTags = 33;
const int KeywordStart = 19;
const int NumberOfKeyword = 14;
const int SymbolStart = 3;
const int NumberOfSymbol = 16;

const int BadToken = 0;
const int Identifier = 1;
const int NumericalValue = 2;

const std::string KeywordTable[NumberOfKeyword] =
{
    "begin", "end", "if", "then", "while",
    "do", "call",  "const", "var", "procedure",
    "read", "write", "else", "odd"
};

const std::string SymbolTable[NumberOfSymbol] =
{
    "+", "-", "*", "/",
    "=", "<>", "<", "<=",
    ">", ">=", "(", ")",
    ",", ";", ".", ":="
};

const std::string TagTable[NumberOfTags] = {
    "bad",
    "identifier",
    "number",
    "plus",
    "minus",
    "asterisk",
    "slash",
    "equal",
    "nequal",
    "less",
    "lessequal",
    "grater",
    "graterequal",
    "parenthesisl",
    "parenthesisr",
    "comma",
    "semicolon",
    "period",
    "become",
    "begin",
    "end",
    "if",
    "then",
    "while",
    "do",
    "call",
    "const",
    "var",
    "procedure",
    "read",
    "write",
    "else",
    "odd"
};

enum class Tag {
    Bad,
    Identifier,
    Number,
    Plus,
    Minus,
    Asterisk,
    Slash,
    Equal,
    NEqual,
    Less,
    LessEqual,
    Grater,
    GraterEqual,
    ParenthesisL,
    ParenthesisR,
    Comma,
    SemiColon,
    Period,
    Become,
    Begin,
    End,
    If,
    Then,
    While,
    Do,
    Call,
    Const,
    Var,
    Procedure,
    Read,
    Write,
    Else,
    Odd
};
const Tag Tags[] = {
    Tag::Bad,
    Tag::Identifier,
    Tag::Number,
    Tag::Plus,
    Tag::Minus,
    Tag::Asterisk,
    Tag::Slash,
    Tag::Equal,
    Tag::NEqual,
    Tag::Less,
    Tag::LessEqual,
    Tag::Grater,
    Tag::GraterEqual,
    Tag::ParenthesisL,
    Tag::ParenthesisR,
    Tag::Comma,
    Tag::SemiColon,
    Tag::Period,
    Tag::Become,
    Tag::Begin,
    Tag::End,
    Tag::If,
    Tag::Then,
    Tag::While,
    Tag::Do,
    Tag::Call,
    Tag::Const,
    Tag::Var,
    Tag::Procedure,
    Tag::Read,
    Tag::Write,
    Tag::Else,
    Tag::Odd
};

static std::string TagToString(Tag tag) {
    for (int i = 0; i < NumberOfTags; ++i) {
        if (tag == Tags[i])
            return TagTable[i];
    }
    return "wtf"; //What a terrible failure!
}