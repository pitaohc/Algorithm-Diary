#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"
#include <semaphore>
using namespace std;
class FizzBuzz {
private:
    int n;
    int cur; // 四个线程都需要访问cur，所以需要加锁
    binary_semaphore sem;
public:
    FizzBuzz(int n) :cur(1), sem(1) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            sem.acquire();
            int cur = this->cur;
            if (cur <= n && cur % 3 == 0 && cur % 5 != 0) {
                printFizz();
                ++cur;
            }
            this->cur = cur;
            sem.release();
            if (cur > n) {
                return;
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            sem.acquire();
            int cur = this->cur;
            if (cur <= n && cur % 3 != 0 && cur % 5 == 0) {
                printBuzz();
                ++cur;
            }
            this->cur = cur;
            sem.release();
            if (cur > n) {
                return;
            }

        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            sem.acquire();
            if (cur <= n && cur % 3 == 0 && cur % 5 == 0) {
                printFizzBuzz();
                ++cur;
            }
            this->cur = cur;
            sem.release();
            if (cur > n) {
                return;
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            sem.acquire();
            int cur = this->cur;
            if (cur <= n && cur % 3 != 0 && cur % 5 != 0) {
                printNumber(cur);
                ++cur;
            }
            this->cur = cur;
            sem.release();
            if (cur > n) {
                return;
            }
        }
    }
};

