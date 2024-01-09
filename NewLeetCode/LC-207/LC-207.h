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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegrees(numCourses, 0);
        //建立图，同时统计入度
        for (const auto& edge : prerequisites) {
            ++indegrees[edge[0]];
            graph[edge[1]].emplace_back(edge[0]);
        }
        //添加入度为0的节点到访问队列
        queue<int> visit;
        int visitedNodeNum = 0;
        for (int node = 0; node < numCourses; ++node) {
            if (indegrees[node] == 0) {
                visit.push(node);
            }
        }
        //拓扑排序
        while (!visit.empty()) {
            const int node = visit.front();
            visit.pop();
            ++visitedNodeNum; // 访问计数+1
            for (const int next : graph[node]) {
                --indegrees[next];
                if (indegrees[next] == 0) { //如果邻居的入度为0，就添加到访问队列
                    visit.push(next);
                }
            }
        }

        return visitedNodeNum == numCourses;
    }
};

