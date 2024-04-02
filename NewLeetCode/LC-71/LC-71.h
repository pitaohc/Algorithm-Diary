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
    string simplifyPath(string path) {
        deque<string> s;
        const int n = path.size();

        for (int i = 0; i < n; )
        {
            int start = i;
            do
            {
                ++i;
            } while (i < n && path[i] != '/');
            int end = i;
            string cur = path.substr(start, end - start);
#ifdef _DEBUG
            fmt::print("cur: {}, path: {}\n", cur, s);
#endif // _DEBUG
            if (cur == "/." || cur == "/") {
                continue;
            }
            else if (cur == "/..") {
                if (!s.empty()) {
                    s.pop_back();
                }
            }
            else {
                s.push_back(cur);
            }
        }
        if (s.empty()) {
            return "/";
        }
        else {
            auto it = s.begin();
            string res;
            while (it != s.end()) {
                res += *it;
                ++it;
            }
            return res;
        }
    }
};

