#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>
#include<functional>
using namespace std;
class Solution {
private:
    void dfs(vector<int>& status, vector<vector<int>>& res, int n, int k) {
        if (k <= 0) {
            res.emplace_back(status);
            return;
        }
        k--;
        int begin = (status.empty()) ? 1 : *(--status.end()) + 1;
        for (int i = begin; i <= n - k; i++) {
            status.emplace_back(i);
            dfs(status, res, n, k);
            status.pop_back();
        }
        k++;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> status;

        dfs(status, res, n, k);
        return res;
    }
};

//class Solution {
//
//public:
//    vector<vector<int>> combine(int n, int k) {
//        vector<vector<int>> res;
//        vector<int> status;
//        status.reserve(k);
//        res.reserve(n * n);
//        struct DFS {
//            vector<vector<int>>& res;
//            vector<int>& status;
//            int& n;
//            void operator()(int num, int k) {
//                if (k <= 0) {
//                    res.emplace_back(status);
//                    return;
//                }
//                k--;
//                for (int i = num; i <= n - k; i++) {
//                    status.emplace_back(i);
//                    this->operator()(i + 1, k);
//                    status.pop_back();
//                }
//                k++;
//            }
//            DFS(vector<vector<int>>& res,
//                vector<int>& status,
//                int& n) :res(res), status(status), n(n) {}
//        }dfs(res, status, n);
//        dfs(1, k);
//
//        return res;
//    }
//};