# [118. 杨辉三角](https://leetcode.cn/problems/pascals-triangle/)

## 题面

给定一个非负整数 $numRows$，生成「杨辉三角」的前 $numRows$ 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

![](https://pic.leetcode-cn.com/1626927345-DZmfxB-PascalTriangleAnimated2.gif)

>示例 1:  
输入: `numRows = 5`  
输出: `[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]`

>示例 2:  
输入: `numRows = 1`  
输出: `[[1]]`


## 思路
一行作为一个数组，该三角形实际上是一个下三角形。观察可知，中间元素由上一行的左右两个元素相加组成，左右两边都为1。
在下三角中，`a[i][j]=a[i-1][j-1]+a[i-1][j]`。那么我们可以得到转移公式：  
1. j=0 或 j=i,则`a[i][j]=1`
1. else, `a[i][j]=a[i-1][j-1]+a[i-1][j]`