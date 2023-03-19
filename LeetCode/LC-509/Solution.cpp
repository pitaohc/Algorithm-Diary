#include "Solution.h"
#include"Solution.h"
#include<vector>
using namespace std;


int Solution::fib(int n)
{
    if (n == 0) return 0;
    vector<int> fib_arr(n + 1);
    fib_arr[0] = 0;
    fib_arr[1] = 1;
    for (size_t i = 2; i <= n; i++)
    {
        fib_arr[i] = fib_arr[i - 1] + fib_arr[i - 2];
    }
    return fib_arr[n];
}
