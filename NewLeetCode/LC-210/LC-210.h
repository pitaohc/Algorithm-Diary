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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0); // 统计当前课程的前置数量
        vector<int> res;
        vector<vector<int>> graph(numCourses, vector<int>()); // 记录当前课程的后置课程
        for (auto& edge : prerequisites) {
            int& course = edge[0];
            int& req = edge[1];
            graph[req].push_back(course);
            indegree[course]++;
        }
        queue<int> visit;
        //放入无前置课程的课程
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                visit.push(i);
            }
        }
        while (!visit.empty()) {
            int course = visit.front();
            visit.pop();
            res.push_back(course);
            for (auto& next : graph[course]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    visit.push(next);
                }
            }
        }
        if (res.size() == numCourses) {
            return res;
        }
        else {
            return {};
        }
    }
};

