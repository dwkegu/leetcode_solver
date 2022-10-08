#pragma once
// #include <rapidjson/document.h>

class Solver {
    public:
        Solver() {}
        virtual ~Solver() {}
        virtual void solve()=0;
};