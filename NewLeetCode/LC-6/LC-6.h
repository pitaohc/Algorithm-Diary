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
    string convert(string s, int numRows) {
        if (numRows < 1) {
            //抛出异常
            throw "numRows must be greater than 0";
        }
        if (numRows == 1) {
            return s;
        }
        const int n = s.size();
        const int blockSize = numRows * 2 - 2; // 一块的字符长度
        const int blockRowSize = numRows - 1; // 一块占用的列数
        const int blockCount = s.size() / blockSize + (s.size() % blockSize);
        vector<string> buffer(numRows, string());
#ifdef _DEBUG
        fmt::print(fmt::fg(fmt::color::yellow), 
            "块长度: {}\n"
            "块列数: {}\n"
            "块数量: {}\n", blockSize,blockRowSize,blockCount);
#endif // _DEBUG
        for (int i = 0; i < n; i++)
        {
            int blockIndex = i / blockSize;
            int blockOffset = i % blockSize;
            int col=0, row=0;
            if (blockOffset < numRows ) {
                col = blockOffset;
                row = blockIndex * blockRowSize;
                
            }
            else {
                col = 2 * numRows - 2  - blockOffset;
                row = blockIndex * blockRowSize + blockOffset - numRows + 1;
            }
            buffer[col].push_back(s[i]);
        }
#ifdef _DEBUG
        for (const auto& s : buffer) {
            cout << s << endl;
        }
#endif // _DEBUG

        //TODO
        stringstream ss;
        for (const auto& s : buffer) {
            ss << s;
        }
        return ss.str();
    }
};
