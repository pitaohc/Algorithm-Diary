#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"
#include <semaphore>
using namespace std;
class Foo {
private:
    binary_semaphore s1;
    binary_semaphore s2;
    binary_semaphore s3;

public:
    Foo() :s1(1), s2(0), s3(0) {

    }

    void first(function<void()> printFirst) {
        s1.acquire();
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        s2.release();
    }

    void second(function<void()> printSecond) {
        s2.acquire();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        s3.release();
    }

    void third(function<void()> printThird) {
        s3.acquire();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
