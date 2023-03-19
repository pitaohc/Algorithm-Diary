#include<iostream>
#include"stdc++.h"
#include"Solution.h"
using namespace std;
int main()
{
    Solution sol;
    vector<int> g, s;

    //case 1
    g = { 1,2,3 };
    s = { 1,1 };
    cout << sol.findContentChildren(g, s) << endl;

    g = { 1,2 };
    s = { 1,2,3 };
    cout << sol.findContentChildren(g, s) << endl;
    return 0;
}