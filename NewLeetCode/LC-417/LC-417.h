#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int x, int y) {
        const int n = heights.size(), m = heights[0].size();
        const static vector<pair<int, int>> directories = { {0,1},{1,0},{0,-1},{-1,0} }; // right,down,left,up
        if (ocean[x][y]) { //�Ѿ����ʹ��Ľڵ�
            return;
        }
        ocean[x][y] = true; //���ʵ�ǰ��
        for (const auto& directory : directories) {
            int newX = x + directory.first, newY = y + directory.second;
            if (newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
            if (!ocean[newX][newY] && heights[newX][newY]>=heights[x][y]){
                //�ж��µĵ��Ƿ��Ѿ����ʹ������ж��µĵ��Ƿ���ڵ��ڵ�ǰ��
                //�ж��Ƿ��Ѿ����ʹ����Լ�С�㷨ʱ�䣬��Ϊ���ú������ж��������Ա��ⲻ��Ҫ�ĵ���
                dfs(heights, ocean, newX, newY);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> Pacific(n,vector<bool>(m)), Atlantic(n, vector<bool>(m));
        vector<vector<int>> result;

        for (int i = 0; i < n; i++)
        {
            dfs(heights, Pacific, i, 0);
            dfs(heights, Atlantic, i, m-1);

        }
        for (int j = 0; j < m; j++)
        {
            dfs(heights, Pacific, 0, j);
            dfs(heights, Atlantic, n-1, j);

        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (Pacific[i][j] && Atlantic[i][j]) {
                    result.push_back({ i,j });
                }
            }
        }
        return result;
    }
};
