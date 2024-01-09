#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
private:
    unordered_map<string, string> parentsMap; //字符串的parent
    unordered_map<string, double> valuesMap; // 当前字符串到parent的权值

    //寻找祖先，并进行路径压缩
    const string findAncient(const string& node) {
        if (parentsMap[node] == node) {
            return node;
        }
        string parent = parentsMap[node];
        string result = parentsMap[node] = findAncient(parent);
        valuesMap[node] *= valuesMap[parent];
        return result;
    }

    //构建并查集
    void buildUnionSet(vector<vector<string>>& equations, vector<double>& values) {
        const int n = equations.size();
        for (int i = 0; i < n; ++i) {
            const auto& equation = equations[i]; // eq:= left/right = value
            const auto& value = values[i];
            const auto& left = equation[0];
            const auto& right = equation[1];

            auto itLeft = parentsMap.find(left), itRight = parentsMap.find(right);

            if (itLeft == parentsMap.end() && itRight == parentsMap.end()) {
                // 两个字符串都不在并查集中
                // left作为right的父节点
                parentsMap.insert({ left,left });
                parentsMap.insert({ right,left });
                valuesMap.insert({ left,1.0f });
                valuesMap.insert({ right,value });
            }
            else if (itLeft != parentsMap.end() && itRight == parentsMap.end())
            {
                // 第二个字符串不在并查集中
                const auto& ancient = findAncient(left);
                parentsMap.insert({ right,ancient });
                valuesMap.insert({ right,value * valuesMap[left] });
            }
            else if (itLeft == parentsMap.end() && itRight != parentsMap.end())
            {
                // 第一个字符串不在并查集中
                const auto& ancient = findAncient(right);
                parentsMap.insert({ left,ancient });
                valuesMap.insert({ left, valuesMap[right] / value });
            }
            else {
                // 两个字符串都在并查集中
                // 检查两个字符串是否在同个集合中
                const auto& ancientLeft = findAncient(left);
                const auto& ancientRight = findAncient(right);
                if (ancientLeft == ancientRight) { //两个字符串在同一个集合中
                    continue;
                }

                parentsMap[ancientRight] = ancientLeft;
                valuesMap[ancientRight] = valuesMap[left] * value / valuesMap[right];
            }
        }
    }
    double div(const vector<string>& query) {
        const string& left = query[0];
        const string& right = query[1];
        double result = -1.0f; // 默认情况当left和right不在同一个集合
        if (parentsMap.find(left) == parentsMap.end() ||
            parentsMap.find(right) == parentsMap.end()) {
            // 如果其中一个字符串不存在
            result = -1.0f;
        }
        else if (findAncient(left) == findAncient(right)) {
            result = valuesMap[right] / valuesMap[left];
        }
        return result;
    }
public:
    vector<double> calcEquation(
        vector<vector<string>>& equations, vector<double>& values,
        vector<vector<string>>& queries) {

        buildUnionSet(equations, values);

        const int n = queries.size();
        vector<double> result;
        result.reserve(n);
        for (auto& query : queries) {
            result.emplace_back(div(query));
        }
        return result;
    }
};
