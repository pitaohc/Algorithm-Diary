#include<iostream>
#include"Solution.h"
using namespace std;

void print(vector<vector<int>> vect)
{
    for each (vector<int> row in vect)
    {

        for each (int num in row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
int main()
{
    Solution sol;
    auto res = sol.fib(5);
    cout << res << endl;
    return 0;
}