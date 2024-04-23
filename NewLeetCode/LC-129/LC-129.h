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
    using ll = long long;
    ll sum = 0;
    ll cur = 0;
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        if (node && !node->left && !node->right) {
            //р╤вс╫з╣Ц
            cur = cur * 10 + node->val;
            sum += cur;
            cur = cur / 10;
            return;
        }
        cur = cur * 10 + node->val;
        if (node->left) {
            dfs(node->left);
        }
        if (node->right) {
            dfs(node->right);
        }
        cur /= 10;
    }
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        dfs(root);
        return sum;
    }
};
