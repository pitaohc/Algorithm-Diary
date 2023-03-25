#pragma once
#include"stdc++.h"
#include"util.h"
class Solution {
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
        using namespace std;
        sort(people.begin(), people.end(), [](const auto& left, const auto& right)
            {
                if (left[0] == right[0])
                    return left[1] < right[1];
                else
                    return left[0] > right[0];
            });
        //cout << "first sorted:" << endl;
        //cout << people << endl;

        vector<vector<int>> res;
        for (const auto& person : people)
        {
            res.insert(res.begin() + person[1], person);
        }
        //cout << "res:\n" << res << endl;
        return res;
    }
};