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
    vector<int> parents;
    int find(int x) {
        if (parents[x] == x) {
            return x;
        }
        return parents[x] = find(parents[x]);
    }
    void merge(int x, int y) {
        int px = find(x), py = find(y);
        parents[py] = px;
    }
    bool connected(int x,int y) {
        return find(x) == find(y);
    }
public:
    bool equationsPossible(vector<string>& equations) {
        parents.resize(26);
        for(int i = 0; i < 26; i++) {
            parents[i] = i;
        }

        for (const auto& equation : equations) {
            if (equation[1] == '=') {
                int left = equation[0] - 'a';
                int right = equation[3] - 'a';
                merge(left, right);
            }
        }
        for (const auto& equation : equations) {
            if (equation[1] == '!') {
                int left = equation[0]-'a';
                int right = equation[3] - 'a';
                if (connected(left, right)) {
                    return false;
                }
            }
        }
        return true;
    }
};

