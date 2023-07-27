#pragma once

#include"stdc++.h"
#include"List.h"

using std::string;
using std::vector;

class Solution {
public:
    string findLongestWord(string s, vector<string> &dictionary) {
        auto sort_cmp = [](const string &s1, const string &s2) -> bool {
            if (s1.size() == s2.size())
                return s1 < s2;
            else
                return s1.size() > s2.size();
        };
        std::sort(dictionary.begin(), dictionary.end(), sort_cmp);

        for (auto &s: dictionary) {
            std::cout << s << std::endl;
        }

        auto find = [](const string &sub, const string &target) -> bool {
            size_t ps = 0, pt = 0;
            if (sub.size() > target.size()) return false;
            while (pt < target.size()) {
                if (sub[ps] == target[pt]) {
                    ++ps;
                }
                ++pt;
            }
            return ps == sub.size();
        };
        for (auto &elem: dictionary) {
            if (find(elem, s)) {
                return elem;
            }
        }

        return {};
    }
};