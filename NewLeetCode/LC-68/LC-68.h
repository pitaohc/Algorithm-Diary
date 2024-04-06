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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<int>> buffers(1);
        int lastline = 0;
        const int n = words.size();
        int i = 0;
        int curSize = 0;
        //将字符串装载到行缓存区中
        while (i < n) {
            //如果当前单词能装载到当前行缓冲区，则将id放到末尾
            if (curSize + words[i].size() <= maxWidth) {
                buffers[lastline].emplace_back(i);
                curSize += words[i].size() + 1;
                ++i;
            }
            else { //长度不够，新增一行
                buffers.push_back({});
                ++lastline;
                curSize = 0;
            }
        }
#ifdef _DEBUG
        for (const auto& line : buffers) {
            cout << "{";
            if (!line.empty()) {
                cout << words[line[0]];
                for (int i = 1; i < line.size(); i++)
                {
                    cout << ", " << words[line[i]] ;
                }
            }
            cout << "}\n";
        }
#endif // _DEBUG

        vector<string> res;
        //提取缓冲区，输出实际的字符串
        for (size_t i = 0; i < lastline; i++)
        {
            int wordSize = buffers[i].size(); // 单词个数
            stringstream ss;
            if (wordSize == 1) {
                int spaceSize = maxWidth - words[buffers[i][0]].size();
                ss << words[buffers[i][0]]<<string(spaceSize,' ');
            }
            else {
                int charSize = 0; //字符个数
                for (const auto& id : buffers[i]) {
                    charSize += words[id].size();
                }
                int spaceSize = maxWidth - charSize;
                int spaceWidth = spaceSize / (wordSize - 1);
                int spaceRem = spaceSize % (wordSize - 1);
                for (int j = 0; j < wordSize - 1; ++j) {
                    ss << words[buffers[i][j]] << string(spaceWidth + (spaceRem > 0), ' ');
                    --spaceRem;
                }
                ss << words[buffers[i][wordSize - 1]];
            }
#ifdef _DEBUG
            cout<<i<<": " << ss.str() << endl;
#endif // _DEBUG

            res.emplace_back(ss.str());
        }

        //最后一行
        {
            stringstream ss;
            ss << words[buffers[lastline][0]];
            for (size_t i = 1; i < buffers[lastline].size(); i++)
            {
                ss<<' '<< words[buffers[lastline][i]];
            }

            ss << string(maxWidth - ss.str().size(), ' ');
            res.emplace_back(ss.str());
        }
        return res;
    }
};
