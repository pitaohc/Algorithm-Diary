#include<iostream>
#include"stdc++.h"
#include"Solution.h"
#include"util.h"

using namespace std;


int main() {
    Solution sol;
    vector<string> dict;
    string s, ans, res;
    //case 1
    s = "abpcplea";
    dict = {"ale", "apple", "monkey", "plea"};
    res = sol.findLongestWord(s, dict);
    cout << "res: " << res << endl;

    //case 2
    s = "abpcplea";
    dict = {"a", "b", "c"};
    res = sol.findLongestWord(s, dict);
    cout << "res: " << res << endl;

    //case 3
    s = "abpcplea";
    dict = {"z", "d", "h"};
    res = sol.findLongestWord(s, dict);
    cout << "res: " << res << endl;

    return 0;
}