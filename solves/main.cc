#include <iostream>
#include <memory>
#include "config.h"

// #include TARGET_HEAD

#define GET_SOLVER(x) std::make_shared<P##x>();

int main() {
    // auto& solver = GET_SOLVER(2424);
    // solver->solve();
    std::cout << TARGET_HEAD << std::endl;
    return 0;
}