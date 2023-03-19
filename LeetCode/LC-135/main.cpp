#include<iostream>
#include"stdc++.h"
#include"Solution.h"
using namespace std;


int main()
{
    Solution sol;
    vector<int> ratings;
    int result = 0;

    //case1
    ratings = { 1,0,2 };
    result = sol.candy(ratings);
    cout << result << endl;

    //case2
    ratings = { 1,2,2 };
    result = sol.candy(ratings);
    cout << result << endl;
    return 0;
}