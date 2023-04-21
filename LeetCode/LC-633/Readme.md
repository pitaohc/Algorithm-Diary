# [633. 平方数之和](https://leetcode.cn/problems/sum-of-square-numbers/)

## 题面

给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。


## 思路

从小到大遍历a，利用a和c计算得到b，b = sqrt(c-a^2)，判断b是否是整数