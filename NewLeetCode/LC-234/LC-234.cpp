#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-234.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
using namespace std;

int main() {
    Solution sol;
    int caseNum = 1;
    ListNode* head;
    bool res, ans;

    fmt::print("Case {}\n", caseNum++);
    head = NodeFactory({ 1,2,3,2,1 });
    ans = true;
    res = sol.isPalindrome(head);
    fmt::print("ans = {}, res = {}, result corrent: {}\n", ans, res, ans == res);

    fmt::print("Case {}\n", caseNum++);
    head = NodeFactory({ 1,2,3,3,2,1 });
    ans = true;
    res = sol.isPalindrome(head);
    fmt::print("ans = {}, res = {}, result corrent: {}\n", ans, res, ans == res);

    fmt::print("Case {}\n", caseNum++);
    head = NodeFactory({ 1,2,2,1 });
    ans = true;
    res = sol.isPalindrome(head);
    fmt::print("ans = {}, res = {}, result corrent: {}\n", ans, res, ans == res);

    fmt::print("Case {}\n", caseNum++);
    head = NodeFactory({ 1,2,1 });
    ans = true;
    res = sol.isPalindrome(head);
    fmt::print("ans = {}, res = {}, result corrent: {}\n", ans, res, ans == res);

    fmt::print("Case {}\n", caseNum++);
    head = NodeFactory({ 1,2 });
    ans = false;
    res = sol.isPalindrome(head);
    fmt::print("ans = {}, res = {}, result corrent: {}\n", ans, res, ans == res);

    return 0;
}
