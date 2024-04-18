#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> queMin; //存放比num小的元素 less:最大元素在堆顶
    priority_queue<int, vector<int>, greater<int>> queMax;

public:
    MedianFinder() :queMin(), queMax() {

    }

    void addNum(int num) {
        //优先存放queMin
        if (queMin.empty() || num <= queMin.top()) {
            queMin.push(num);
            if (queMax.size() + 1 < queMin.size()) {
                //queMin比queMax多两个及以上的元素
                queMax.push(queMin.top());
                queMin.pop();
            }
        }
        else {
            queMax.push(num);
            if (queMax.size() > queMin.size()) {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }

    double findMedian() {
        if (queMin.size() == queMax.size()) {
            return (queMin.top() + queMax.top()) / 2.0;
        }
        else {
            return queMin.top();
        }
    }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
