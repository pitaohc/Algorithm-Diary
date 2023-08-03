//
// Created by devcpp on 23-7-25.
//
#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-34-Solution.h"

using namespace std;

int main() {
    Solution sol;
    vector<int> nums, res;
    int target;

    //case 1
    nums = {5, 7, 7, 8, 8, 10};
    target = 8;
    res = sol.searchRange(nums, target);
    cout << "Case 1\n"
         << res << endl;
    //case 2
    nums = {5, 7, 7, 8, 8, 10};
    target = 6;
    res = sol.searchRange(nums, target);
    cout << "Case 2\n"
         << res << endl;
    //case 3
    nums = {};
    target = 6;
    res = sol.searchRange(nums, target);
    cout << "Case 3\n"
         << res << endl;
    //case 3
    nums = {6};
    target = 6;
    res = sol.searchRange(nums, target);
    cout << "Case 3\n"
         << res << endl;

    return 0;
}