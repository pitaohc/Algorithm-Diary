#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-322.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<int> coins;
    int amount, ans, res;

    fmt::print("Case {}\n", caseNum++);
    coins = { 2,4 };
    amount = 11;
    ans = -1;
    fmt::print(
        "amount = {}, coins: {}\n"
        "ans = {}, ",
        amount, coins, ans);
    res = sol.coinChange(coins, amount);
    fmt::print("res = {}\n", res);
    return 0;
}
