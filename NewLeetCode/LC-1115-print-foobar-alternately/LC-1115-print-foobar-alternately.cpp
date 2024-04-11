#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-1115-print-foobar-alternately.h"
#include "List.h"
#include "util.h"
#include "Tree.h"
#include <thread>
using namespace std;
void test(
    int n = 1
) {
    static int caseNum = 1;
    fmt::print(fmt::fg(fmt::color::yellow), "Case {}\n", caseNum++);

    FooBar fooBar(n);
    //新建一个线程，调用fooBar的foo方法
    thread t1(&FooBar::foo, &fooBar, []() { cout << "foo"; });
    //新建一个线程，调用fooBar的bar方法
    thread t2(&FooBar::bar, &fooBar, []() { cout << "bar"; });
    t1.join();
    t2.join();
    cout << endl;

}
int main() {
    test();
    test(2);


    return 0;
}
