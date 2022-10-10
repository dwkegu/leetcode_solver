#include "../problems.h"

std::string P1688::solve() {
    std::stringstream ss;
    ss << std::to_string(n) << ":" << std::to_string(n - 1) << "\n";
    return ss.str();
}

int P1688::solve_example() {
    if (read_doc()) {
        return 1;
    }
    for(rapidjson::SizeType i = 0; i < document.Size(); i++) {
        auto& item = document[i];
        if (!item.HasMember("n")) {
            std::cout << "not found n in example\n";
        }
        n = item["n"].GetInt();
        solve_ts();
    }
    return 0;
}