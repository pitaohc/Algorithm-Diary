#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-63.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

void test(vector<vector<int>> grid, int ans) {
    Solution sol;
    static int caseNum = 1;
    fmt::print("Case {}\n", caseNum++);

    int res = sol.uniquePathsWithObstacles(grid);

    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "Pass!\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "Fail!\n");
        fmt::print("Expected: {}\n",ans);
        fmt::print("Actually: {}\n",res);
        
    }
}
int main() {

    test({ {0,0},{0,0 } }, 2);
    test({ {0,0,0},{0,0,0},{0,0,0} }, 6);
    test({ {0,0,0},{0,1,0},{0,0,0} }, 2);

    return 0;
}
