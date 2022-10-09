#include "problems.h"
#include <iostream>

/**
 * 主要思想：存储每个item是否传输完成，并且统计当前最长序号。
 * 优化点1：内存优化，朴素的想法是用map储存，可以用bit数组存储，减少内存消耗，空间复杂度O(n)
 * 优化点2：复杂度优化，每次插入当前最长序号下一位则向前遍历是否存在更长序号，时间复杂度O(1)
 */

std::string P2424::solve() {
    std::stringstream ss;
    int array_size = n / 8;
    if (n % 8 != 0) {
        array_size ++;
    }
    char* array = new char[array_size];
    int lower_bound = 0;
    int ltsp = 0;
    for (auto& video : uploads) {
        video --;
        int idx = video / 8;
        int bit_num = video % 8;
        array[idx] |= (1 << bit_num);
        if (video == ltsp) {
            while ((lower_bound < array_size && (array[lower_bound] >> (ltsp % 8)) & 0x1) == 0x1) {
                ltsp ++;
                lower_bound = ltsp / 8;
            } 
        }
        ss << std::to_string(n) << ", uploads: " << std::to_string(video) << ", longest: " << std::to_string(ltsp) << "\n";        
    }
    return ss.str();
}

int P2424::solve_example() {
    if (read_doc()) {
        return 1;
    }
    for(rapidjson::SizeType i = 0; i < document.Size(); i++) {
        auto& item = document[i];
        if (!item.HasMember("n") || !item.HasMember("upload")) {
            std::cout << "no n and upload kv\n";
            return -1;
        }
        n = item["n"].GetInt();
        auto upload_array = item["upload"].GetArray();
        uploads.clear();
        for (rapidjson::SizeType j = 0; j < upload_array.Size(); j++) {
            uploads.push_back(upload_array[j].GetInt());
        }
        solve_ts();
    }
    return 0;
}