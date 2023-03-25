#include<iostream>
#include"stdc++.h"
#include"Solution.h"
#include"util.h"
using namespace std;


int main()
{
    Solution sol;
    vector<vector<int>> people, ans, res;

    //case 1
    people = {
        {7,0},
        {4,4},
        {7,1},
        {5,0},
        {6,1},
        {5,2} };
    ans = {
        {5,0},
        {7,0},
        {5,2},
        {6,1},
        {4,4},
        {7,1} };
    res = sol.reconstructQueue(people);
    cout << "Case " << 1 << endl
        << "People:\n"
        << people << endl
        << "Ans:\n"
        << ans << endl
        << "Res:\n"
        << res << endl
        << endl;

    //case 2
    people = {
        {6,0},
        {5,0},
        {4,0},
        {3,2},
        {2,2},
        {1,4},
    };
    ans = {
        {4,0},
        {5,0},
        {2,2},
        {3,2},
        {1,4},
        {6,0},
    };
    res = sol.reconstructQueue(people);
    cout << "Case " << 2 << endl
        << "People:\n"
        << people << endl
        << "Ans:\n"
        << ans << endl
        << "Res:\n"
        << res << endl
        << endl;


    return 0;
}