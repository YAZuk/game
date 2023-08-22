#include <iostream>

#include "Unit.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    auto unit1 = unit::Unit();

    unit::Unit unit2(std::move(unit1));



    return 0;
}
