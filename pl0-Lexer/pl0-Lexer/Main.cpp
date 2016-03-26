#include "Lexer.h"

#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::string ifilename;
    // std::cin >> filename;
    ifilename = "./test.pl0";
    Lexer lexer(ifilename);
    lexer.Tokenizer();

    std::string ofilename = "./Lexer-output.txt";
    std::ofstream fout(ofilename, std::ios_base::out);

    std::string content = lexer.TokensToString();
    fout << content << std::endl;
    fout.close();
    std::cout << content;

    return 0;
}