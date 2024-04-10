#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-146.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(vector<string> ops, vector<vector<int>> nums, vector<int> ans) {
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    LRUCache cache(nums[0][0]);
    for (int i = 1; i < ops.size(); i++)
    {
        if (ops[i] == "put") {
            fmt::print(fmt::fg(fmt::color::yellow), "put [{},{}]\n", nums[i][0], nums[i][1]);
            cache.put(nums[i][0], nums[i][1]);
        }
        else {

            fmt::print(fmt::fg(fmt::color::yellow), "get [{}]\n", nums[i][0]);
            int res = cache.get(nums[i][0]);
            fmt::print(fmt::fg(fmt::color::yellow), "    get [{}] = {}\n", nums[i][0], res);
        }
    }
}


void test1() {
    LRUCache sol(2);
    int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);
    fmt::print("put(1, 1)\n");
    sol.put(1, 1);
    fmt::print("put(2, 2)\n");
    sol.put(2, 2);
    fmt::print("get(1) -> {}\n", sol.get(1));
    fmt::print("put(3, 3)\n");
    sol.put(3, 3);
    fmt::print("get(2) -> {}\n", sol.get(2));
    fmt::print("put(4, 4)\n");
    sol.put(4, 4);
    fmt::print("get(1) -> {}\n", sol.get(1));
    fmt::print("get(3) -> {}\n", sol.get(3));
    fmt::print("get(4) -> {}\n", sol.get(4));
}
int main() {
    //test1();
    test({ "LRUCache","put","put","get","put","get","put","get","get","get" },
        { {2} ,{1,1},{2,2},{1},{3,3},{2},{4,4},{1},{3},{4} },
        { null, null, null, 1, null, -1, null, -1, 3, 4 });
    test({ "LRUCache", "put", "put", "put", "put", "get", "get", "get", "get", "put", "get", "get", "get", "get", "get" },
        { {3}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {4}, {3}, {2}, {1}, {5, 5}, {1}, {2}, {3}, {4}, {5} },
        { null, null, null, null, null, 4, 3, 2, -1, null, -1, 2, 3, -1, 5 });
    return 0;
}
