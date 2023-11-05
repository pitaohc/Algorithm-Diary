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
        vector<int> primes(1,2);
        for (size_t num = 2; num < n; num++)
        {
            bool isPrime = true;
            for (int prime : primes)
            {
                if (num % prime == 0)
                {
                    isPrime = false;
                    break;
                }
                if (prime * prime > num)
                {
                    break;
                }
            }
            if (isPrime)
            {
                primes.push_back(num);
            }
        }
        return primes.size();
    }
};