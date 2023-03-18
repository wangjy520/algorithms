# review
- [1039-多边形三角形的最优剖分](https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/)
    - `dp[i][j]`为从顶点`i`到顶点`j`的最小值，以i-j的线段为底边， 枚举每个底边对应的顶点
    - `dp[i][j] = min{dp[i][k] + dp[k][j] + a[i] * a[j] * a[k]}, i < k <= j`
- https://ac.nowcoder.com/acm/problem/13134
  - 最长上升子序列变形
  - 统计从左开始最长上升连续子序列的长度以及从右侧开始最长连续下降子序列的长度，枚举每个断点，如果`a[i + 1] - a[i - 1] >= 2`，可以修改断点`i`，更新答案为`res = max(res, left[i - 1] + right[i + 1] + 1)`