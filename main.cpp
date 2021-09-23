#include <iostream>
#include "BigInt.h"

int main() {
    BigInt a;
    BigInt b;
    std::cin >> a >> b;
    std::cout << a << '\n' <<  b << '\n' << a + b << '\n' << a - b;

    return 0;
}
