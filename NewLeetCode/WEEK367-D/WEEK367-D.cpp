#include "List.h"
#include "util.h"
#include <iostream>
#include "WEEK367-D.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<vector<int>> grid,ans,res;

    fmt::print("Case {}\n", caseNum++);
    grid ={ 
    {1,2,},
    {3,4,},
    };
    ans = {
    {24,12,},
    {8,6,},
    };
    fmt::print("Input: {}\n", grid);
    res = sol.constructProductMatrix(grid);
    fmt::print("ans: {}\n"
        "res: {}\n", ans, res);
    return 0;
}
