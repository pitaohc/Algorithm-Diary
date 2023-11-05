#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
        {
            return 0;
        }
        vector<bool> isPrimes(n, true);
        isPrimes[0] = isPrimes[1] = false;
            
        for (size_t num = 2; num < n; num++)
        {
            if (!isPrimes[num])
            {
                continue;
            }
            for (size_t target = num*2; target < n; target+=num)
            {
                isPrimes[target] = false;

            }
        }
        return count_if(isPrimes.begin(), isPrimes.end(), [](auto val) {return val; });
    }
};