#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                result[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            result[s.top()] = 0;
            s.pop();
        }

        return result;

    }
};
 