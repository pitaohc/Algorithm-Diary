#include<iostream>
#include"Solution.h"
using namespace std;

void print(vector<vector<int>> vect)
{
    for each (vector<int> row in vect)
    {

        for each (int num in row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
int main()
{
    Solution sol;
    vector<int> vect;
    int result, answer;
    //case1
    vect = { 1,2,3,1 };
    answer = 4;
    result = sol.rob(vect);
    cout << "ans\tres\n";
    cout << answer << "\t" << result << endl;


    return 0;
}