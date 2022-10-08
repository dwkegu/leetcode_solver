#pragma once
#include <memory>
#include "problems.h"

// #define PROBLEM_NUM 2424
#define _GET_SOLVER(x) std::make_shared<P##x>()
#define GET_SOLVER(x) _GET_SOLVER(x)
