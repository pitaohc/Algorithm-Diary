#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-417.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<vector<int>> heights, ans, res;
    fmt::print("LC-417\n");


    heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    ans = {{0,4},{1,3},{1,4},{2,2},{3,0},{3,1},{4,0}};
    res = sol.pacificAtlantic(heights);
    fmt::print("Case {}\n"
        "heights:\n"
        "{}\n"
        "ans = {}\n"
        "res = {}\n", 
        caseNum++,heights,ans,res);

    heights = { {2,1},{1,2} };
    ans = { {0,0},{0,1}, {1,0}, {1,1} };
    res = sol.pacificAtlantic(heights);
    fmt::print("Case {}\n"
        "heights:\n"
        "{}\n"
        "ans = {}\n"
        "res = {}\n",
        caseNum++, heights, ans, res);

    heights = { {2} };
    ans = { {0,0} };
    res = sol.pacificAtlantic(heights);
    fmt::print("Case {}\n"
        "heights:\n"
        "{}\n"
        "ans = {}\n"
        "res = {}\n",
        caseNum++, heights, ans, res);

    return 0;
}
