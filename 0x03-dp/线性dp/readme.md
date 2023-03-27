# 线性dp

- [0x00-合唱队形](https://www.luogu.com.cn/problem/P1091)

- [0x01-删数 - 洛谷](https://www.luogu.com.cn/problem/P2426)

- [0x02-饥饿的奶牛 - 洛谷](https://www.luogu.com.cn/problem/P1868)
  
  - dp[i]为前i个区间的最优值
  
  - <mark>排序 + 线性dp + 二分</mark>

- [0x03-[NOIP2000 提高组] 乘积最大 - 洛谷](https://www.luogu.com.cn/problem/P1018)

- https://ac.nowcoder.com/acm/problem/13134
  - 最长上升子序列变形
  - 统计从左开始最长上升连续子序列的长度以及从右侧开始最长连续下降子序列的长度，枚举每个断点，如果`a[i + 1] - a[i - 1] >= 2`，可以修改断点`i`，更新答案为`res = max(res, left[i - 1] + right[i + 1] + 1)`
- https://leetcode.cn/problems/best-team-with-no-conflicts/
  - 转换成最长上升子序列问题
  - 先按照年龄为第一关键字、分数为第二关键字升序排序，`dp[i]`表示以第i个人结尾的最大分数，`dp[i] = max(dp[i], dp[j] + scores[id[i]])，当scores[id[j]] <= scores[id[i]]`
- https://leetcode.cn/problems/count-substrings-that-differ-by-one-character/
  - 双序列问题。`dp[i][j][k]`表示以`s[i - 1], t[j - 1]`结尾且不需要改变/需要改变一个字符的子字符串数量
  ```cpp
  if(s[i - 1] == t[j - 1]) {
      dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
      dp[i][j][1] = dp[i - 1][j - 1][1];
  }
  else {
      dp[i][j][1] = dp[i - 1][j - 1][0] + 1;
  }
  ```

