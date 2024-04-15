#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"
#include <array>
using namespace std;
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        const int geneSize = startGene.size();
        const int gengTypeCnt = 4;
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.count(endGene) == 0) {
            return -1;
        }
        unordered_map<string, unsigned short> visitedMap;
        queue<string> que({ startGene });
        visitedMap.insert({ startGene,1 });
        array<char, gengTypeCnt> keys({ 'A','C','G','T' });
        while (!que.empty()) {
            string gene = que.front();
            que.pop();
            int pathLen = visitedMap[gene];
            for (int i = 0; i < geneSize; i++)
            {
                string newGene = gene;
                for (char key : keys) {
                    newGene[i] = key;
                    if (newGene == endGene) {
                        return pathLen;
                    }
                    // 存在路径，但没有访问过
                    if (bankSet.find(newGene) != bankSet.end() && visitedMap.find(newGene) == visitedMap.end()) {
                        visitedMap.insert({ newGene,pathLen + 1 });
                        que.push(newGene);
                    }
                }
            }
        }


        return -1;
    }
};
