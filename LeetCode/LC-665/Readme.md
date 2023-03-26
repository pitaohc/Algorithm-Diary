# [665. 非递减数列](https://leetcode.cn/problems/non-decreasing-array)

## 题面

给你一个长度为 n 的整数数组 nums ，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。


## 思路

依然是贪心，但是策略不是看到下降就修改，因为修改当前元素可能会影响后面的排列。
所以需要尽可能降低修改的印象，尽量把前一个数减小，而不是把当前的数变大。

当 nums[i] 破坏了数组的单调递增时，即 nums[i] < nums[i - 1]  时，为了让数组有序，我们发现一个规律（在上面三个例子中， nums[i] 都为 2， nums[i -1] 都为 4）：

如例①的情况，当 i = 1 ，那么修改 num[i- 1] ，不要动 nums[i] ，因为nums[i]后面的元素是啥我们还不知道呢，少动它为妙。  
如例②的情况，当 i > 1 时，我们应该优先考虑把 nums[i - 1] 调小到 >= nums[i - 2] 并且 <= nums[i]。同样尽量不去修改 nums[i] ，理由同上。  
如例③的情况，当 i > 1 且 nums[i] < nums[i - 2] 时，我们无法调整 nums[i - 1] ，我们只能调整 nums[i] 到 nums[i - 1] 。  

作者：fuxuemingzhu  
链接：[3 张动图帮助你理解这道题目怎么想，秒懂！](https://leetcode.cn/problems/non-decreasing-array/solution/3-zhang-dong-tu-bang-zhu-ni-li-jie-zhe-d-06gi/)  
来源：力扣（LeetCode）  
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。  