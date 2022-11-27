#include "Solution.h"
#include"Solution.h"
#include<vector>
using namespace std;
vector<vector<int>> Solution::generate(int numRows)
{
	vector<vector<int>> res(numRows,vector<int>());
	for (size_t i = 0; i < numRows; i++)
	{
		res[i].resize(i + 1);
	}
	for (size_t i = 0; i < numRows; i++)
	{
		res[i][0] = 1;
		for (size_t j = 1; j < i; j++)
		{
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
		res[i][i] = 1;
	}
    return res;
}
