#include<iostream>
#include"stdc++.h"
#include"Solution.h"
#include"util.h"
using namespace std;


int main()
{
    Solution sol;
    vector<vector<int>> points;
    int ans, res;
    //case 1
    points = { {10,16},{2,8},{1,6},{7,12} };
    ans = 2;
    res = sol.findMinArrowShots(points);
    cout << "Case " << 1 << endl
        << "Points: \n" << points << endl
        << "Result = " << res << "\tAnswer = " << ans << endl
        << endl;

    //case 2
    points = { {1,2},{3,4},{5,6},{7,8} };
    ans = 4;
    res = sol.findMinArrowShots(points);
    cout << "Case " << 2 << endl
        << "Points: \n" << points << endl
        << "Result = " << res << "\tAnswer = " << ans << endl
        << endl;

    //case 3
    points = { {1,2},{2,3},{3,4},{4,5} };
    ans = 2;
    res = sol.findMinArrowShots(points);
    cout << "Case " << 3 << endl
        << "Points: \n" << points << endl
        << "Result = " << res << "\tAnswer = " << ans << endl
        << endl;

    return 0;
}