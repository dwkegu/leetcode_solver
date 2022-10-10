#include "../problems.h"
#include <iostream>

/** 
 * problem link https://leetcode.com/problems/previous-permutation-with-one-swap/
 */

std::string P1053::solve() {
    std::stringstream ss;
    int size = array.size();
    int pre_min = array[size-1];
    int swap_pos = -1;
    for (int i = size - 2; i >= 0; i--) {
        if (array[i] > pre_min) {
            swap_pos = i;
            break;
        } else if (array[i] < pre_min) {
            pre_min = array[i];
        }
    }
    if (swap_pos >= 0) {
        int max_swap_num = 0;
        int max_swap_pos = 0;
        for (int i = swap_pos + 1; i < size; i++) {
            if (array[i] > max_swap_num && array[i] < array[swap_pos]) {
                max_swap_num = array[i];
                max_swap_pos = i;
            }
        }
        ss << std::to_string(swap_pos) << "<->" << std::to_string(max_swap_pos) << "\n";
    } else {
        ss << "no swap\n";
    }    
    return ss.str();
}

int P1053::solve_example() {
    if (read_doc()) {
        return 1;
    }
    for(rapidjson::SizeType i = 0; i < document.Size(); i++) {
        auto& item = document[i];
        if (!item.HasMember("array")) {
            std::cout << "no array kv\n";
            return -1;
        }
        auto array_vec = item["array"].GetArray();
        array.clear();
        for (rapidjson::SizeType i = 0; i < array_vec.Size(); i++) {
            array.push_back(array_vec[i].GetInt());
        }
        solve_ts();
    }
    return 0;
}