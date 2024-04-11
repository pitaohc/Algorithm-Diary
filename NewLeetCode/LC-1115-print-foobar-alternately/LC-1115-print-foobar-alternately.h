#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"
#include <semaphore>
using namespace std;
class FooBar {
private:
    int n;
    binary_semaphore semFoo;
    binary_semaphore semBar;

public:
    FooBar(int n) :semFoo(1), semBar(0) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            semFoo.acquire();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            semBar.release();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            semBar.acquire();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            semFoo.release();
        }
    }
};
