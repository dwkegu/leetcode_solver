#include "../problems.h"
#include <iostream>
#include <unordered_set>

 int minDistance(std::string& word1, std::string& word2) {
    const int l1 = word1.size();
    const int l2 = word2.size();
    std::vector<std::vector<int>> dp(l1+1,std::vector<int>(l2+1,0));
    for(int i=0;i<=l1;++i){
        dp[i][0] = i;
    }
    for(int i=0;i<=l2;++i){
        dp[0][i] = i;
    }
    dp[0][0] = 0;
    for(int i=1;i<=l1;++i){
        for(int j=1;j<=l2;++j){
            if(word1[i-1]==word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1+std::min(dp[i-1][j-1],std::min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }
    return dp[l1][l2];
}

std::string P1000003::solve() {
    int dis = minDistance(s1, s2);
    return std::to_string(dis) + '\n';
}

int P1000003::solve_example() {
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
    s1 = "abc";
    s2 = "cabac";
    solve_ts();
    return 0;
}