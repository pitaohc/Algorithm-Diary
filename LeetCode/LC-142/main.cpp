#include<iostream>
#include"stdc++.h"
#include"Solution.h"
#include"List.h"
#include"util.h"
using namespace std;


int main()
{
    Solution sol;
    vector<int> nums;
    ListNode* head, * result;
    //case 1
    nums = { 1,2,3,4 };
    head = NodeFactory(nums);
    result = sol.detectCycle(head);
    cout << "Case" << 1 << endl
        << "List: " << head << endl
        << (int*)result << endl;
    //case 2
    nums = { 1,2,3,4 };
    head = NodeFactory(nums);
    head->next->next->next->next = head->next; //4->2
    result = sol.detectCycle(head);
    cout << "Case2" << 1 << endl
        //<< "List: " << head << endl
        << (int*)result << ": " << result->val << endl;

    return 0;
}