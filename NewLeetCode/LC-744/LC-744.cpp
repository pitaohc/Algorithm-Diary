#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-744.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;

void test(vector<char> letters, char target, char ans)
{
    Solution sol;
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("letters: {}\n", letters);
    fmt::print("target: {}\n", target);


    auto res = sol.nextGreatestLetter(letters,target);
    if (res == ans) {
        fmt::print(fmt::fg(fmt::color::green), "Pass\n");
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "Fail\n");
        fmt::print("Expect: {}\n", ans);
        fmt::print("Output: {}\n", res);
    }
}

int main()
{
    test({'e','e','e','e','e','e','n','n','n','n'},'e','n');
    test({'c', 'f', 'j'},'g','j');
    // letters = ['c', 'f', 'j']，target = 'a'
    test({'c', 'f', 'j'},'a','c');
    
    //输入: letters = ['x','x','y','y'], target = 'z'
    //输出: 'x'
    test({'x','x','y','y'},'z','x');

    //输入: letters = ['c','f','j'], target = 'c'
    //输出: 'f'
    test({'c', 'f', 'j'},'c','f');
    test({'c', 'f', 'j'},'d','f');


    return 0;
}
