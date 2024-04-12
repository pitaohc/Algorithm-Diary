#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-1117-building-h2o.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
using namespace std;
void test(
    int n
) {
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);
    fmt::print("Input: {}\n", n);

    H2O h2o;
    vector<thread> threads;
    thread t1([&h2o,&n]() {
        for (int i = 0; i < 2*n; i++) {
            h2o.hydrogen([]() { fmt::print("H"); });
        }
    });
    thread t2([&h2o, &n]() {
        for (int i = 0; i < n; i++)
        {
            h2o.oxygen([]() {fmt::print("O"); });
        }
        });
    t1.join();
    t2.join();
    fmt::print("\n");
   


}
int main() {

    test(1);
    test(3);

    return 0;
}
