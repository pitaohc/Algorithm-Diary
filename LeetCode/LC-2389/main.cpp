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
template<class T>
ostream& operator<<(ostream& out, vector<T> vect)
{
    out << "[";
    for (const auto& item : vect)
    {
        out << item << ", ";
    }
    out << "\b\b]";
    return out;
}
int main()
{
    Solution sol;
    vector<int> nums{ 4,5,2,1 };
    vector<int> queries{ 3,10,21 };
    auto& res = sol.answerQueries(nums, queries);
    cout << res << endl;

    nums = { 2,3,4,5 };
    queries = { 1 };
    res = sol.answerQueries(nums, queries);
    cout << res << endl;
    return 0;
}