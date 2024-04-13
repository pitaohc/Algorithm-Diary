#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"
#include <semaphore>
#include <mutex>
#include <condition_variable>
using namespace std;
class DiningPhilosophers {
#define N 5
    mutex m;
    mutex forks[N];
    void pickForks(int id) {
        m.lock();
        forks[id].lock();
        forks[(id + 1) % N].lock();
    }
    void putForks(int id) {
        forks[(id + 1) % N].unlock();
        forks[id].unlock();
        m.unlock();

    }
public:
    DiningPhilosophers() {

    }

    void wantsToEat(int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork) {
        pickForks(philosopher);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        putForks(philosopher);
    }
};