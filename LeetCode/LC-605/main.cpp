#include<iostream>
#include"stdc++.h"
#include"Solution.h"
#include"util.h"
using namespace std;


int main()
{
    Solution sol;
    vector<int>flowerbed;
    int n;
    bool result;
    bool answer;
    //case 1
    flowerbed = { 1,0,0,0,1 };
    n = 1;
    result = sol.canPlaceFlowers(flowerbed, n);
    answer = true;
    cout << "Case " << 1 << endl
        << "flowered:" << flowerbed << endl
        << "n = " << n << endl
        << "result = " << result << endl
        << "answer = " << answer << endl
        << endl;
    //case 2
    flowerbed = { 1,0,0,0,1 };
    n = 2;
    result = sol.canPlaceFlowers(flowerbed, n);
    answer = false;
    cout << "Case " << 2 << endl
        << "flowered:" << flowerbed << endl
        << "n = " << n << endl
        << "result = " << result << endl
        << "answer = " << answer << endl
        << endl;

    return 0;
}