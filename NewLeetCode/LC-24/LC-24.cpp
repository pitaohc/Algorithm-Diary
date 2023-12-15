#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-24.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    ListNode* head, *res;
    //例子1 
    fmt::print("Case {}\n", caseNum++);
    head = NodeFactory({ 1,2,3,4 });
    cout << "original: " << head << endl;
    res = sol.swapPairs(head);
    cout << "result: " << res << endl;

    return 0;
}
