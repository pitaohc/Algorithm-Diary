#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include "LC-1195-fizz-buzz-multithreaded.h"
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
    fmt::print("Input: {}\n", n);
    FizzBuzz fizz(n);
    function<void()> printFizz = [] {cout << "fizz" << ", "; };
    function<void()> printBuzz = [] {cout << "buzz" << ", "; };
    function<void()> printFizzBuzz = [] {cout << "fizzbuzz" << ", "; };
    function<void(int)> printNum = [](int num) {cout << num << ", "; };
    vector<thread> threads;
    threads.push_back(thread(&FizzBuzz::fizz, &fizz, printFizz));
    threads.push_back(thread(&FizzBuzz::buzz, &fizz, printBuzz));
    threads.push_back(thread(&FizzBuzz::fizzbuzz, &fizz, printFizzBuzz));
    threads.push_back(thread(&FizzBuzz::number, &fizz, printNum));

    for (auto& t : threads) {
        t.join();
    }
    cout << endl;
}
int main() {

    test(1);
    test(5);
    test(15);
    test(30);

    return 0;
}
