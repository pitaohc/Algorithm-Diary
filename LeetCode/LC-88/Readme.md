# [88. 合并两个有序数组](https://leetcode.cn/problems/merge-sorted-array/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china)

## 题面

给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

## 思路

因为需要在原数组上修改，需要考虑数据覆盖的问题。
如果从前往后比较，可能会覆盖还没有合并的nums1。
那么我们考虑另一个方向——从后往前比较。把值较大的先放入。
