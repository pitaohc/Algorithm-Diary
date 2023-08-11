//
// Created by devcpp on 23-7-25.
//
#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-81-Solution.h"

using namespace std;

int main() {
    Solution sol;
    vector<int> nums;
    int target;
    bool res;

    nums = {2, 5, 6, 0, 0, 1, 2};
    target = 0;
    cout << "Case " << 1 << endl
         << "nums: " << nums << endl
         << "target: " << target << endl
         << "result: " << (sol.search(nums, target) ? "True" : "False") << endl;
    nums = {2, 5, 6, 0, 0, 1, 2};
    target = 3;
    cout << "Case " << 2 << endl
         << "nums: " << nums << endl
         << "target: " << target << endl
         << "result: " << (sol.search(nums, target) ? "True" : "False") << endl;
    return 0;
}