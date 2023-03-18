# 二分
- [259-较小的三数之和](https://leetcode.cn/problems/3sum-smaller/)
    - 二分查找
    - 运算符有确定的关系，给定3个就能找到第4个。循环枚举前两个数，二分搜索第三个数，更新答案
- https://leetcode.cn/contest/biweekly-contest-100/problems/minimum-time-to-repair-cars/
    - 二分答案
    - 如果`x`时间内能够完成，那么`y > x`的情况下也能够完成。固定时间，求能够修理的最多车辆数