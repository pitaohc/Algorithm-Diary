#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        const string startAitport = "JFK"; //起始机场
        unordered_map<string,multiset<string>> graph;
        //将航线存入graph
        for (auto& ticket : tickets) {
            graph[ticket.front()].insert(ticket.back());
        }
#ifdef _DEBUG
        fmt::print("graph: {}\n", graph);
#endif
        vector<string> result ;
        stack<string> s;
        s.push(startAitport);
        while (!s.empty()) {
            string next = s.top(); //拷贝
            if (graph[next].empty()) { //发现已经到了终点
                result.emplace_back(std::move(next)); //向结果放置终点
                //因为next不会再使用了，所以此处使用了移动语义
                s.pop();
            }
            else {
                auto it = graph[next].begin();
                s.push(*it);
                graph[next].erase(it);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};