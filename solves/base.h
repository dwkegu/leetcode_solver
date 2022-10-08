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
#include <rapidjson/document.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>

class Solver {
    public:
        Solver() {}
        virtual ~Solver() {}
        void solve_ts() {
            auto start = std::chrono::system_clock::now();
            std::string result = solve();
            auto end = std::chrono::system_clock::now();
            auto ts = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            std::cout << "time cost : " << ts.count() << " us" << std::endl;
            std::cout << result << std::endl;
        }
        virtual std::string solve()=0;
        virtual int solve_example()=0;
        virtual std::string get_example_filename()=0;
        int read_doc() {
            std::stringstream ss;
            std::ifstream in;
            in.open(get_example_filename(), std::ifstream::in);
            ss << in.rdbuf();
            in.close();
            if (document.Parse(ss.str().c_str()).HasParseError()) {
                std::cout << "document parse failed\n";
                return -1;
            }
            return 0;
        }
    
    public:
        rapidjson::Document document;
};