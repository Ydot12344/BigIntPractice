#include <iostream>
#include "BigInt.h"
#include <unordered_map>
#include "Parser.h"

int main() {
    std::string expr;
    std::getline(std::cin, expr);
    Parser<BigInt> parser(expr);

    std::cout << parser.expression();
    return 0;
}
