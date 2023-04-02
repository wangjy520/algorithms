# 最短路💭💡🎈
- https://atcoder.jp/contests/abc254/tasks/abc254_e
    - 因为k最大是3并且每个节点的度最大为3，直接对每个查询执行BFS
- https://leetcode.cn/problems/cheapest-flights-within-k-stops/
    - 将原来的图扩展一个维度，然后执行最短路算法
- [0x01](https://www.luogu.com.cn/problem/P6175)
    - 最小环
    - 枚举每一条边`<u, v>`，将其断开，以u为起点做最短路，本次遍历的最小环的值就是`g[u][v] + d[v]`