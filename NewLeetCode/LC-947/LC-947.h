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
    unordered_map<int, int> fathers, ranks;
    int find(int x) {
        if (fathers.find(x) == fathers.end()) {
            fathers[x] = x;
            ranks[x] = 1;
        }
        return fathers[x] == x ? x : fathers[x] = find(fathers[x]);
        // 如果x的祖先就是自己则返回自己，如果不是，则调用find向上查找，并记录到fathers[x]中，再返回
    }
    void unionSet(int x, int y) {
        int xFather = find(x), yFather = find(y);
        if (xFather == yFather) {
            return;
        }
        if (ranks[xFather] < ranks[yFather]) {
            swap(xFather, yFather);
        }
        ranks[xFather] += ranks[yFather];
        fathers[yFather] = xFather;
    }
    int count() {
        int num = 0;
        for (const auto& [x, father] : fathers) {
            num += x == father;
        }
        return num;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        const int n = stones.size();

        for (const auto& stone:stones) {
            unionSet(stone[0], -1 - stone[1]);
        }

        return n - count();
    }
};
