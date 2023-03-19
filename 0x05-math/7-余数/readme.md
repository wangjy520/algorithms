# 余数
- https://leetcode.cn/contest/weekly-contest-337/problems/smallest-missing-non-negative-integer-after-operations/
    - 哈希表 + 取余
    - 答案不会超过`n`，对于一个数num，判断是否可以得到它，只需要看原数组中是否存在num模value同余的数字存在，只有这样才可以通过加减value得到，使用哈希表统计即可