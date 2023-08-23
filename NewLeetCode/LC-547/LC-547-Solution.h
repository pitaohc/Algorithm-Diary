//
// Created by devcpp on 23-8-15.
//

#ifndef LC_547_SOLUTION_H
#define LC_547_SOLUTION_H
#define DEBUG
#include<cmath>
#include<vector>
#include<fmt/core.h>
#include<queue>
using namespace std;
class Solution {
private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& isVisited, int city) {
        if (isVisited[city]) return;

        isVisited[city] = true;
        int n = isConnected.size();
        for (size_t i = 0; i < n; i++)
        {
            if (isConnected[city][i]) {
                dfs(isConnected, isVisited, i);
            }
        }

    }
    void bfs(vector<vector<int>>& isConnected, vector<bool>& isVisited, int city) {
        int n = isConnected.size();
        queue<int> visitQueue;
        visitQueue.push(city);
        while (!visitQueue.empty()) {
            int city = visitQueue.front();
            visitQueue.pop();
            isVisited[city] = true;
            for (int j = 0; j < n; ++j) {
                if (isVisited[j] || !isConnected[city][j]) continue;
                visitQueue.push(j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int result = 0;
        vector<bool> isVisited(n, false);
        for (size_t i = 0; i < n; i++)
        {
            if (isVisited[i]) continue;
            ++result;
            //bfs(isConnected, isVisited, i);
            dfs(isConnected, isVisited, i);
        }
        return result;
    }
};
#endif //LC_547_SOLUTION_H
