# 字典序问题
- https://leetcode.cn/problems/previous-permutation-with-one-swap/
    - 求小于当前排列的最大排列
    - 从右向左找到第一个逆序对，左边的就是要交换的元素，用右侧的最大值交换，然后将该位置右侧降序排序。本题要求只交换一次，所以不需要排序