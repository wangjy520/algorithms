# 区间动态规划
- [1039-多边形三角形的最优剖分](https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/)
    - `dp[i][j]`为从顶点`i`到顶点`j`的最小值，以i-j的线段为底边， 枚举每个底边对应的顶点
    - `dp[i][j] = min{dp[i][k] + dp[k][j] + a[i] * a[j] * a[k]}, i < k <= j`
    