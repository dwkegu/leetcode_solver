#include "problems.h"

std::string P1883::solve() {
    std::stringstream ss;
    long* m1 = new long[dist.size() + 1]{0};
    long* m2 = new long[dist.size() + 1]{0};
    long target_length = (long)hour * (long)speed;
    long* tmp;
    auto get_no_skip_length = [&](const long& last_length, const long& current_dist, const int& pos) {
        if (pos == dist.size() - 1 || (last_length + current_dist) % speed == 0) {
            return current_dist;
        }
        return speed - (last_length + current_dist) % speed + current_dist;
    };
    for(size_t i = 0; i <= dist.size(); i++) {
        m2[0] = 0;
        if (i == 0) {
            for (int j = 0; j < dist.size(); j++) {
                m1[j+1] = m1[j] + get_no_skip_length(m1[j], dist[j], j);
            }
            if (m1[dist.size()] <= target_length) {
                ss << "skip 0 with hour " << std::to_string(m1[dist.size()]) << "/" << speed << "\n";
                ss << std::to_string(m1[dist.size()]) << ", " << std::to_string(target_length) << "\n";
                break;
            }
            continue;
        }
        for (int j = 1; j < dist.size() + 1; j++) {
            if (j <= i) {
                m2[j] = m2[j-1] + dist[j-1];
            } else {
                int cur_no_skip_length = get_no_skip_length(m2[j-1], dist[j-1], j-1);
                if (m2[j-1] + cur_no_skip_length < m1[j-1] + dist[j-1]) {
                    m2[j] = m2[j-1] + cur_no_skip_length;
                } else {
                    m2[j] = m1[j-1] + dist[j-1];
                }
            }
            // std::cout << "[" << std::to_string(i) << "] row m2[" << std::to_string(j) << "] = " << std::to_string(m2[j]) << std::endl;
        }
        if (m2[dist.size()] <= target_length) {
            ss << "skip " << std::to_string(i) << " with hour " << std::to_string(m2[dist.size()]) << "/" << speed << "\n";
            break;
        }
        tmp = m1;
        m1 = m2;
        m2 = tmp;
        tmp = nullptr;
    }
    delete[] m1;
    delete[] m2;
    return ss.str();
}


int P1883::solve_example() {
    if (read_doc()) {
        return 1;
    }
    for (rapidjson::SizeType i = 0; i < document.Size(); ++i) {
        auto& item = document[i];
        // read input
        if (!item.HasMember("dist") || !item.HasMember("speed") || !item.HasMember("hour")) {
            std::cout << "example error\n";
        }
        dist.clear();
        auto dist_array = item["dist"].GetArray();
        for(rapidjson::SizeType i = 0; i < dist_array.Size(); ++i) {
            dist.push_back(dist_array[i].GetInt());
        }
        speed = item["speed"].GetInt();
        hour = item["hour"].GetInt();
        solve_ts();
    }
    return 0;
}