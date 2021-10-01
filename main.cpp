#include <iostream>
#include "BigInt.h"
#include <unordered_map>

std::unordered_map<std::string, BigInt (BigInt::*) (const BigInt&) const> arithmetic_op = {
        {"+", &BigInt::operator+}, {"-", &BigInt::operator-}, {"*", &BigInt::operator*},
        {"/", &BigInt::operator/}, {"%", &BigInt::operator%}
};

std::unordered_map<std::string, bool (BigInt::*) (const BigInt&) const> logic_op = {
        {">", &BigInt::operator>}, {">=", &BigInt::operator>=},{"<", &BigInt::operator<},
        {"<=", &BigInt::operator<=}, {"==", &BigInt::operator==}, {"!=", &BigInt::operator!=}
};

int main() {
    BigInt a;
    BigInt b;
    std::string op;
    std::cin >> a  >> op >> b;

    if(arithmetic_op.find(op) != arithmetic_op.end())
        std::cout << (&a->*(arithmetic_op[op]))(b);
    else if(logic_op.find(op) != logic_op.end())
        std:: cout << (&a->*(logic_op[op]))(b);
    return 0;
}
