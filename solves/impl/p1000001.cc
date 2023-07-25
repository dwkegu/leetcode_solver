#include "../problems.h"
#include <iostream>
#include <unordered_set>

void edit_one(const std::string& s, std::unordered_set<std::string>& result) {
    int s_length = s.size();
    for (int i = 0; i < s.size(); i++) {
        // 删除
        std::string one = s.substr(0, i) + s.substr(i + 1, s_length - i - 1);
        result.insert(one);
        for (char a = 'a'; a <= 'z'; a++) {
            if (a == s.at(i)) {
                continue;
            }
            one = s.substr(0, i) + std::string(1, a) + s.substr(i+1, s_length - i - 1);
            result.insert(one);
        }
        for (char a = 'a'; a <= 'z'; a++) {
            one = s.substr(0, i) + std::string(1, a) + s.substr(i, s_length - i);
            result.insert(one);
        }        
    }
    for (char a = 'a'; a <= 'z'; a++) {
        std::string one = s + std::string(1, a);
        result.insert(one);
    }
}

std::string P1000001::solve() {
    std::unordered_set<std::string> result;
    edit_one(input, result);
    std::unordered_set<std::string> result2;
    for (auto& s : result) {
        edit_one(s, result2);
    }
    return std::to_string(result2.size()) + '\n';
}

int P1000001::solve_example() {
    // if (read_doc()) {
    //     return 1;
    // }
    // for(rapidjson::SizeType i = 0; i < document.Size(); i++) {
    //     auto& item = document[i];
    //     if (!item.HasMember("n") || !item.HasMember("upload")) {
    //         std::cout << "no n and upload kv\n";
    //         return -1;
    //     }
    //     n = item["n"].GetInt();
    //     auto upload_array = item["upload"].GetArray();
    //     uploads.clear();
    //     for (rapidjson::SizeType j = 0; j < upload_array.Size(); j++) {
    //         uploads.push_back(upload_array[j].GetInt());
    //     }
    //     solve_ts();
    // }
    input = "a";
    solve_ts();
    return 0;
}