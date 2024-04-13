#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
class Solution {
private:
    int n;
    pair<int, int> getPos(int id) {
        --id;
        int col = n - 1 - (id / n);
        int temp = id % n;
        int row = ((id / n) % 2 == 0) ? temp : n - 1 - temp;
        return { col,row };
    }


public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        vector<int> vis(n * n + 1);
        queue<pair<int, int>> q;
        q.emplace(1, 0);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 1; i <= 6; ++i) {
                int nxt = p.first + i;
                if (nxt > n * n) { // �����߽�
                    break;
                }
                auto rc = getPos(nxt); // �õ���һ��������
                if (board[rc.first][rc.second] > 0) { // �����߻�����
                    nxt = board[rc.first][rc.second];
                }
                if (nxt == n * n) { // �����յ�
                    return p.second + 1;
                }
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    q.emplace(nxt, p.second + 1); // ��չ��״̬
                }
            }
        }
        return -1;
    }
    
};

