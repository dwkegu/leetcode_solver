#include <iostream>
#include <memory>
#include "config.h"
#include "problems.h"


int main() {
    auto solver = GET_SOLVER(PROBLEM_NUM);
    solver->solve();
    return 0;
}