#include<iostream>
#include"stdc++.h"
#include"Solution.h"
#include"List.h"
#include"util.h"
using namespace std;


int main()
{
    Solution sol;
    string s;
    bool res, ans;

    //case 1
    s = "aba";
    ans = true;
    res = sol.validPalindrome(s);
    cout << "Case 1: " << s << "  " << ((res == ans) ? ("Yes") : ("No")) << endl;
    //case 2
    s = "abca";
    ans = true;
    res = sol.validPalindrome(s);
    cout << "Case 2: " << s << "  " << ((res == ans) ? ("Yes") : ("No")) << endl;
    //case 3
    s = "abc";
    ans = false;
    res = sol.validPalindrome(s);
    cout << "Case 3: " << s << "  " << ((res == ans) ? ("Yes") : ("No")) << endl;
    //case 4
    s = "abcb";
    ans = true;
    res = sol.validPalindrome(s);
    cout << "Case 4: " << s << "  " << ((res == ans) ? ("Yes") : ("No")) << endl;
    //case 5
    s = "ebcbbececabbacecbbcbe";
    ans = true;
    res = sol.validPalindrome(s);
    cout << "Case 5: " << s << "  " << ((res == ans) ? ("Yes") : ("No")) << endl;
    //case 6
    s = "rdsiqgkvzkmhcmrfyizpqfaiwhkaznlhtlvlsjowubyujhwaehssheawhjuybuwojslvlthlnzakhwiaqpziyfrmchmkzvkgqisdr";
    ans = true;
    res = sol.validPalindrome(s);
    cout << "Case 6: " << s << "  " << ((res == ans) ? ("Yes") : ("No")) << endl;
    return 0;
}