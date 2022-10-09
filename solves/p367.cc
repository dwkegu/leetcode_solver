#include "problems.h"
#include <iostream>
#include <unordered_set>
#include <unordered_map>

std::string P367::solve() {
    std::stringstream ss;
    const std::unordered_map<int, std::vector<int>> TAIL2NUM = {{0, {0}}, {1, {1, 9}}, {4, {2, 8}}, {5, {5}}, {6, {4, 6}}, {9, {3, 7}}};
    int tail = num % 10;
    if (!TAIL2NUM.count(tail)) {
        ss << std::to_string(num) << " : false\n";
        return ss.str();
    }
    auto& vec = TAIL2NUM.at(tail);
    int length = 1;
    int num1 = num;
    while(num1 / 10 != 0) {
        length ++;
        num1 /= 10;
    }
    int max_length = length / 2;
    if (length % 2 != 0) {
        max_length ++;
    }
    int cap1 = 1;
    int cap2 = 9;
    if (max_length <= 1) {
        cap1 = 0;
    }
    for (int i = 1; i < max_length; ++i) {
        cap1 *= 10;
        cap2 = cap2 * 10 + 9;
    }
    cap2 = cap2 - cap2 % 10;
    for (auto& item : vec) {
        long low = item + cap1;
        long high = item + cap2;
        long mid = (low + high) / 2;
        while (low <= high) {
            long sq = mid * mid;
            if (sq > num) {
                high = mid - 1;
                mid = (low + high) / 2;
            } else if (sq < num) {
                low = mid + 1;
                mid = (low + high) / 2;
            } else {
                ss << std::to_string(num) << ": true " << std::to_string(mid) << "\n";
                return ss.str();
            }
        }
    }
    ss << std::to_string(num) << " : false\n";
    return ss.str();
}

int P367::solve_example() {
    if (read_doc()) {
        return 1;
    }
    for(rapidjson::SizeType i = 0; i < document.Size(); i++) {
        auto& item = document[i];
        if (!item.HasMember("num")) {
            std::cout << "num not found in example\n";
            return 1;
        }
        num = item["num"].GetInt();
        solve_ts();
    }
    return 0;
}