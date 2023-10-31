#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-123.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<int> prices;
    int ans, res;

    fmt::print("Case {}\n", caseNum++);
    prices = { 3,3,5,0,0,3,1,4 };
    ans = 6;
    fmt::print(
        "prices: {}\n"
        "ans = {}, ", prices, ans);
    res = sol.maxProfit(prices);
    fmt::print("res = {}\n", res);
    return 0;
}
