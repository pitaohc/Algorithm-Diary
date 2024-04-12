#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"
#include <semaphore>
#include <condition_variable>
using namespace std;
class H2O {
private:
    counting_semaphore<2> sem_h;
    counting_semaphore<2> sem_o;

public:
    H2O():sem_h(2), sem_o(0) {

    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_h.acquire(); // 需要一个h的位置，由于sem_h的初始值为2，所以可以保证有两个h的位置
        releaseHydrogen();
        sem_o.release(); // 释放一个o的位置
    }

    void oxygen(function<void()> releaseOxygen) {
        //需要获得两个o的位置，意味着在执行releaseOxygen之前，执行了两次hydrogen
        sem_o.acquire();
        sem_o.acquire();
        releaseOxygen();
        //释放两个h的位置
        sem_h.release();
        sem_h.release();
    }
};

