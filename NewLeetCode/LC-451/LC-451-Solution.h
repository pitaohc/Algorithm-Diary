//
// Created by devcpp on 23-8-15.
//

#ifndef LC_451_SOLUTION_H
#define LC_451_SOLUTION_H
#define DEBUG
#include<cmath>
#include<vector>
#include<fmt/core.h>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {

public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        //cmp判断哪个元素排在后面
        auto cmp = [](const pair<char, int>& left, const pair<char, int>& right) {
            return left.second < right.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        for (char& ch : s) {
            m[ch]++;
        }
        for (auto& elem : m) {
            pq.push(elem);
        }
        m.clear();
        string result;
        while (!pq.empty()) {
            auto& elem = pq.top();
            result.append(string(elem.second, elem.first));
            pq.pop();
        }
        return result;
    }
};
#endif //LC_540_SOLUTION_H
