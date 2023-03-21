#pragma once
#include"stdc++.h"

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {

        int i = 0;
        while (i < flowerbed.size())
        {
            if (flowerbed[i] == 1)
            {
                //当前位置已经有花
                i += 2; //下一个位置肯定不能种
            }
            else
            {
                bool next = (i + 1 == flowerbed.size() || i + 1 < flowerbed.size() && flowerbed[i + 1] == 0);

                if (next)
                {
                    n--;
                    i += 2;
                }
                else
                {
                    i += 3;
                }
            }
        }
        return n <= 0;
    }
};