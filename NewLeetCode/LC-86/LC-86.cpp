#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-86.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(
    vector<int> nums,
    int x,
    vector<int> ans
) {
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("input: {}, {}\n", nums, x);


    ListNode* head = NodeFactory(nums);
    ListNode* ans_head = NodeFactory(ans);
    auto res = sol.partition(head, x);
    stringstream ss;
    stringstream ssans;
    ss << res;
    ssans << ans_head;

    if (ss.str() == ssans.str()) {
        fmt::print(fmt::fg(fmt::color::green), "Pass\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "Fail\n");
        fmt::print("Expect: {}\n", ssans.str());
        fmt::print("Output: {}\n", ss.str());
    }


}
int main() {
    test({ 1,1,1 }, 2, { 1,1,1 });
    test({ 1,1,1 }, 0, { 1,1,1 });

    test({ 1, 4, 3, 2, 5, 2 }, 3, { 1, 2, 2, 4, 3, 5 });
    test({ 1, 1, 4, 3, 2, 5, 2 }, 2, { 1,1,4,3,2,5,2 });
    test({}, 0, {});
    test({ 1 }, 0, { 1 });


    return 0;
}
