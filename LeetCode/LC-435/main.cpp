#include<iostream>
#include"stdc++.h"
#include"Solution.h"
using namespace std;

template<class T>
ostream& operator<<(ostream& out, const vector<T>& vect)
{
    out << "[";
    for (const auto& elem : vect)
    {
        out << elem << ", ";
    }
    out << "\b\b]";
    return out;
}


int main()
{
    Solution sol;
    vector<vector<int>> intervals;
    //case 1
    cout << "Case 1\n";
    intervals = { {1,2},{2,3},{3,4},{1,3}, };//[[1,2],[2,3],[3,4],[1,3]]
    cout << intervals << endl;
    cout << "Result: " << sol.eraseOverlapIntervals(intervals) << endl;
    cout << "Answer: " << 1 << endl << endl;

    //case 2
    cout << "Case 2\n";
    intervals = { {1,2},{1,2},{1,2}, };//[[1,2],[2,3],[3,4],[1,3]]
    cout << intervals << endl;
    cout << "Result: " << sol.eraseOverlapIntervals(intervals) << endl;
    cout << "Answer: " << 2 << endl << endl;

    //case 3
    cout << "Case 3\n";
    intervals = { {1,2},{2,3}, };//[[1,2],[2,3],[3,4],[1,3]]
    cout << intervals << endl;
    cout << "Result: " << sol.eraseOverlapIntervals(intervals) << endl;
    cout << "Answer: " << 0 << endl << endl;


    return 0;
}