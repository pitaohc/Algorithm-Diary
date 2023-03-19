#include "Solution.h"
#include"Solution.h"
#include<vector>
using namespace std;

int Solution::climbStairs(int n)
{
    if (n == 1) return 1;
    else if (n == 2) return 2;

    int n_1 = 2, n_2 = 1;
    int n = 0;
    for (size_t i = 3; i <= n; i++)
    {
        n = n_1 + n_2;
        n_2 = n_1;
        n_1 = n;
    }
    return n;
}
