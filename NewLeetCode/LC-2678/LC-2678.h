#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int countSeniors(vector<string>& details) {
        return count_if(details.begin(), details.end(), [](string& detail) {
            return (detail[11] - '0') * 10 + (detail[12] - '0') > 60; });
    }
};