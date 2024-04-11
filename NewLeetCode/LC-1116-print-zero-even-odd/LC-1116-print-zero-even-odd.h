#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"
#include <semaphore>
using namespace std;
class ZeroEvenOdd {
private:
    binary_semaphore sem_zero, sem_odd, sem_even;
    int n;
    bool isOdd;
public:
    ZeroEvenOdd(int n) :sem_zero(1), sem_odd(0), sem_even(0), isOdd(true) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++)
        {
            sem_zero.acquire();
            printNumber(0);
            if (isOdd) {
                sem_odd.release();
            }
            else {
                sem_even.release();
            }
            isOdd = !isOdd;
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2)
        {
            sem_even.acquire();

            printNumber(i);

            sem_zero.release();

        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2)
        {
            sem_odd.acquire();

            printNumber(i);

            sem_zero.release();

        }
    }
};
