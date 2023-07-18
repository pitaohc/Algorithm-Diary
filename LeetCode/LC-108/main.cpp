#include"stdc++.h"
#include"Solution.h"
using namespace std;
int main()
{
    Solution sol;
    vector<int> vect;
    TreeNode* res;

    //case 1
    vect = { -10,-3,0,5,9 };
    res = sol.sortedArrayToBST(vect);
    return 0;
}