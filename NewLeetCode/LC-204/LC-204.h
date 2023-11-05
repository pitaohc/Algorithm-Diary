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
        vector<int> primes;
        vector<bool> isPrimes(n, true);
        isPrimes[0] = isPrimes[1] = false;
            
        for (size_t num = 2; num < n; num++)
        {
            if (isPrimes[num])
            {
                primes.push_back(num);
            }
            for (int& prime : primes)
            {
                if (prime * num >= n)
                {
                    break;
                }
                isPrimes[prime * num] = false;
            }
        }
        return primes.size();
    }
};