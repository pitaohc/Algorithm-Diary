# [1137. 第 N 个泰波那契数](https://leetcode.cn/problems/n-th-tribonacci-number/)

## 题面

泰波那契序列 Tn 定义如下： 

$T_0 = 0, T_1 = 1, T_2 = 1$ , 且在 $n >= 0$ 的条件下 $T_{n+3} = T_{n} + T_{n+1} + T_{n+2}$

给你整数 n，请返回第 n 个泰波那契数 $T_n$ 的值。

## 思路

动态规划：开一个数组存放数列，从前往后迭代