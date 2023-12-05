#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-303.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    unique_ptr<NumArray> sol;
    vector<int> nums;
    int left, right, ans, res;
    int caseNum = 1;


    fmt::print("Case {}\n", caseNum++);
    nums = { -2, 0, 3, -5, 2, -1 };
    fmt::print("nums: {}\n", nums);
    sol = make_unique<NumArray>(nums);
    left = 2;
    right = 5;
    res = sol->sumRange(left, right);
    return 0;
}
