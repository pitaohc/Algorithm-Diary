#include<iostream>
#include"stdc++.h"
#include"Solution.h"
#include"util.h"
using namespace std;


int main()
{
    Solution sol;
    string s;
    vector<int> res, ans;

    //case 1
    s = "ababcbacadefegdehijhklij";
    ans = { 9,7,8 };
    res = sol.partitionLabels(s);
    cout << "Case " << 1 << endl
        << "S = " << s << endl
        << "Answer = " << ans << endl
        << "Result = " << res << endl
        << endl;

    //case 2
    s = "eccbbbbdec";
    ans = { 10 };
    res = sol.partitionLabels(s);
    cout << "Case " << 2 << endl
        << "S = " << s << endl
        << "Answer = " << ans << endl
        << "Result = " << res << endl
        << endl;

    return 0;
}