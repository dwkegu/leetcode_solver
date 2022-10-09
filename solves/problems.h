/* 
MIT License
@author dwkegu
@date 2022/10/08
Copyright (c) 2022 dwkegu

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once
#include "base.h"
#include <vector>

class P367: public Solver {
    public:
        P367() {}
        ~P367() {}
        std::string solve() override;
        int solve_example() override;
    
    public:
        int num;
};

class P1053: public Solver {
    public:
        P1053() {}
        ~P1053() override {}
        std::string solve() override;
        int solve_example() override;
    public:
        std::vector<int> array;
};

class P1883: public Solver {
    public:
        P1883() {}
        ~P1883() {}
        std::string solve() override;
        int solve_example() override;
    
    public:
        std::vector<int> dist;
        int speed;
        int hour;
};

class P2424: public Solver {

    public:
        P2424() {}
        ~P2424() override {}
        std::string solve() override;
        int solve_example() override;
        void upload(int idx);

    public:
        int n;
        std::vector<int> uploads;


};