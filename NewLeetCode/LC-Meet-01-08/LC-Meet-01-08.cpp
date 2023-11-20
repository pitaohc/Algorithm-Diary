#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-Meet-01-08.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    vector<vector<int>> matrix, ans, res;

    fmt::print("Case {}\n", caseNum++);
    matrix = { {1,0},{1,1} };
    fmt::print("matrix: \n"
        "{}\n", matrix);
    sol.setZeroes(matrix);
    fmt::print("matrix: \n"
        "{}\n", matrix);


    return 0;
}
