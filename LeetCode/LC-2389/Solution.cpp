#include"Solution.h"
#include<algorithm>
using namespace std;

const int Solution::search(const std::vector<int>& preVect, const int query)
{
    int left = 0, right = preVect.size() - 1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;
        if (preVect[mid] == query)
        {
            return mid;
        }
        else if (preVect[mid] < query)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return right;
}

vector<int> Solution::answerQueries(vector<int>& nums, vector<int>& queries)
{
    vector<int> ansVect, preVect;
    sort(nums.begin(), nums.end());
    //建立前缀和数组
    int sum = 0;
    preVect.push_back(sum);
    for (const auto& num : nums)
    {
        sum += num;
        preVect.push_back(sum);
    }
    for (const auto& query : queries)
    {
        ansVect.push_back(this->search(preVect, query));
    }
    return ansVect;
}
