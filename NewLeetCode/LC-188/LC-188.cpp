#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-188.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<int> prices;
    int k;
    int ans, res;

    fmt::print("Case {}\n", caseNum++);
    prices = { 1,2,3 };
    k = 10;
    ans = 2;
    res = sol.maxProfit(k, prices);
    fmt::print("{}\n", res);

    return 0;
}
