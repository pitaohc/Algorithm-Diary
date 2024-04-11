#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-1116-print-zero-even-odd.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
#include <thread>
using namespace std;
void test(
    int n
) {
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    ZeroEvenOdd zero(n);
    function<void(int)> printNum = [](int n) {
        cout << n;
        };

    thread t1(&ZeroEvenOdd::zero, &zero, printNum);
    thread t2(&ZeroEvenOdd::even, &zero, printNum);
    thread t3(&ZeroEvenOdd::odd, &zero, printNum);
    t1.join();
    t2.join();
    t3.join();
    cout << endl;

}
int main() {

    test(1);
    test(2);

    test(10);

    return 0;
}
