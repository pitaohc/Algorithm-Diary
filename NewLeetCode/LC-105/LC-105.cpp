#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-105.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(vector<int> pre, vector<int> in, const vector<int> ansVec) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    TreeNode* ans, *res;
    fmt::print("pre: {}\n"
        "in : {}\n", 
        pre, in);
    ans = buildTree(ansVec);
    res = sol.buildTree(pre, in);
    cout << "ans: " << to_string(ans) << endl;
    cout << "res: " << to_string(res) << endl;
}

int main() {
    test({ 3,9,20,15,7 }, { 9,3,15,20,7 }, { 3,9,20,null,null,15,7 });
    test({ -1 }, { -1 }, { -1 });
    test({}, {}, {});
    return 0;
}
