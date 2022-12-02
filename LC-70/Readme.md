# [70. 爬楼梯](https://leetcode.cn/problems/climbing-stairs/)

## 题面

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

## 思路

滚动数组，动态规划转移方程：$arr_n = arr_{n-1} + arr_{n-2}, if n > 2$,
边界条件：$arr_1 = 1,arr_2 = 2$