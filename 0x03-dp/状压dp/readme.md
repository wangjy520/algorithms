# 状压dp
- https://leetcode.cn/contest/weekly-contest-337/problems/the-number-of-beautiful-subsets/
    - 将子集的选取状态以二进制数表示，`dp[i]`表示在状态`i`的情况是否满足条件。转移时是需要考虑任意一个为1的位置，看这个状态`i`除掉这个元素是否合法以及判断`nums[k]`和剩余的其他数字是否合法，最后统计1~(1 << n)中所有合法的状态