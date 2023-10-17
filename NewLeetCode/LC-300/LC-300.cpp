#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-300.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<int> nums;
    int ans, res;
    fmt::print("Case {}\n", caseNum++);
    nums = { 1,3,5,7,2,4 };
    ans = 4;
    res = sol.lengthOfLIS(nums);

    return 0;
}
