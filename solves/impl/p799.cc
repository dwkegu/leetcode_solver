#include "../problems.h"

std::string P799::solve() {
    std::stringstream ss;
    double* last_level_left = new double[101];
    double* cur_level_left = new double[101];
    double result;
    if (level == 0) {
        result = poured > 1? 1:poured;
        ss << std::to_string(poured) << ", " << std::to_string(level) << ", " << std::to_string(idx) << ": " << std::to_string(result) << "\n";
        return ss.str();
    }
    last_level_left[0] = poured;
    for (int i = 0; i < level; i++) {
        cur_level_left[0] = 0;
        for (int j = 0; j < i+1; j++) {
            cur_level_left[j+1] = 0;
            if (j >= idx - level + i && j <= idx) {
                if (last_level_left[j] > 1) {
                    double half_poured = (last_level_left[j] - 1)/2;
                    cur_level_left[j] += half_poured;
                    cur_level_left[j+1] += half_poured;
                }
            }
        }
        double* tmp = last_level_left;
        last_level_left = cur_level_left;
        cur_level_left = tmp;
        tmp = nullptr;
    }
    ss << std::to_string(poured) << ", " << std::to_string(level) << ", " << std::to_string(idx) << ": " << std::to_string(last_level_left[idx] > 1? 1:last_level_left[idx]) << "\n";
    delete[] last_level_left;
    delete[] cur_level_left;
    return ss.str();
}

int P799::solve_example() {
    if (read_doc()) {
        return 1;
    }
    for(rapidjson::SizeType i = 0; i < document.Size(); i++) {
        auto& item = document[i];
        if (!item.HasMember("poured") || !item.HasMember("query_row") || !item.HasMember("query_glass")) {
            std::cout << "variable not found in example\n";
            return 1;
        }
        level = item["query_row"].GetInt();
        idx = item["query_glass"].GetInt();
        poured = item["poured"].GetDouble();
        solve_ts();
    }
    return 0;
} 