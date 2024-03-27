#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        //if (n == 1) {
        //    return (gas[0] >= cost[0]);
        //}
        int start = 0, end = 0, cur_gas = gas[start];
        while (start < n) {
            if (cur_gas >= cost[end]) { // peek 检查汽油是否够用
                cur_gas -= cost[end];
                end = (end + 1) % n;
                cur_gas += gas[end];
                if (end == start) {
                    return start;
                }
            }
            else { //汽油不够用
                if (start == end) { // 还没出发
                    start = ++end;
                    if (start >= n) {
                        break;
                    }
                    cur_gas = gas[start];
                }
                else {
                    cur_gas -= gas[start];
                    cur_gas += cost[start];
                    ++start;
                }
            }
        }
        return -1;
    }
};
