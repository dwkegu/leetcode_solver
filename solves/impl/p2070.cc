#include "../problems.h"
#include <unordered_map>
#include <algorithm>

std::string P2070::solve() {
	std::string out;
	std::sort(items.begin(), items.end(), [](auto& a, auto& b) {return a[0] < b[0];});
	std::vector<std::pair<int, int>> query_idx_pairs;
	for(int i = 0; i < queries.size(); i++) {
		query_idx_pairs.push_back({queries[i], i});
	}
	std::sort(query_idx_pairs.begin(), query_idx_pairs.end(), [](auto& a, auto& b) {return a.first < b.first;});
	std::vector<int> result;
	result.resize(queries.size());
	int query_idx = 0;
	result[query_idx_pairs[0].second] = 0;
	for (int i = 0; i < items.size(); ) {
		auto& item = items[i];
		if (item[0] <= query_idx_pairs[query_idx].first) {
			// 找到不比当前query贵的pair，检查beauty是否更大
			if (item[1] >= result[query_idx_pairs[query_idx].second]) {
				// 更大则替换当前query 对应的最大beauty
				result[query_idx_pairs[query_idx].second] = item[1];
			}
			i++;
		} else {
			// 比当前query更贵则寻找下一个query
			if (query_idx < queries.size() - 1) {
				result[query_idx_pairs[query_idx+1].second] = result[query_idx_pairs[query_idx].second];
				query_idx ++;
			} else {
				//所有query均已搜索完毕
				break;
			}
		}
	}
	for (int i = query_idx + 1; i < queries.size(); i++) {
		if (result[query_idx_pairs[i].second] < result[query_idx_pairs[i - 1].second]) {
			result[query_idx_pairs[i].second] = result[query_idx_pairs[i - 1].second];
		}
	}
	for (auto& item : result) {
		out += (std::to_string(item) + ", ");
	}
	out += "\n";
	return out;
}

int P2070::solve_example() {
	if (read_doc()) {
		return 1;
	}
	for (rapidjson::SizeType i = 0; i < document.Size(); i++) {
		items.clear();
		queries.clear();
		auto& item  = document[i];
		if (!item.HasMember("items") || !item.HasMember("queries")) {
			std::cout << "example [" << i << "] doesn't contains items or queries" << std::endl;
			continue;
		}
		auto items_array = item["items"].GetArray();
		int num = items_array.Size() / 2;
		for (rapidjson::SizeType j = 0; j < num; j++) {
			int price = items_array[2 * j].GetInt();
			int beauty = items_array[2 * j + 1].GetInt();
			items.push_back({price, beauty});
		}
		auto queries_array = item["queries"].GetArray();
		for (rapidjson::SizeType j = 0; j < queries_array.Size(); j++) {
			queries.push_back(queries_array[j].GetInt());
		}
		solve_ts();
	}
	return 0;
}
