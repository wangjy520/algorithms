# 枚举💭💡🎈
- [795-区间子数组个数](https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/)
    - 枚举右端点，判断合法的左端点有多少个，求满足条件的子数组个数
- [1930-长度为3的不同回文子序列](https://leetcode.cn/problems/unique-length-3-palindromic-subsequences/)
    - 枚举 + 前后缀分解
    - 枚举中间字符，统计每个字符前面及后面每个字符的出现次数
- https://leetcode.cn/problems/bomb-enemy/
    - 预处理 + 枚举
    - 预处理出每个位置上、下、左、右的最大连续敌人数量，枚举每个位置