#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-21.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    ListNode* list1, * list2, * res;
    fmt::print("Case {}\n", caseNum++);
    list1 = NodeFactory({ 1,2,4 });
    list2 = NodeFactory({ 1,3,4 });
    cout << "List1: " << list1<<endl;
    cout << "List2: " << list2<<endl;
    res = sol.mergeTwoLists(list1, list2);
    cout << "res: " << res << endl;
    return 0;
}
