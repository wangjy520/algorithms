# 按照时间顺序更新，方便后续的复习（都是副本）
- [0x01](https://www.luogu.com.cn/problem/P6175)
    - 最小环
    - 枚举每一条边`<u, v>`，将其断开，以u为起点做最短路，本次遍历的最小环的值就是`g[u][v] + d[v]`
- C++中的函数`substr(start, length)`，第一个参数是开始位置，第二个是子串长度
- C++中的三目运算符后两个值必须是同一个类型的
- https://leetcode.cn/problems/minimum-reverse-operations/
  - BFS + set优化
  - 大体思路是在BFS求最短路的同时判断当前节点应该更新到哪些节点。以前做的都是提前建好图再BFS
  - 求最小可以考虑使用BFS求最短路
  - https://leetcode.cn/problems/minimum-reverse-operations/solution/bfstiao-yue-you-xi-jia-qiang-ban-by-tsre-juxn/
  - 想到了BFS，但是建图的时候会TLE。原因在于有很多位置被重复的访问，而这些位置是不会再次被更新的。因为当作图来考虑的话，边权都是1，所以使用普通的BFS就能够更新了，也就是一旦某些位置被访问过了，那么就不需要再次访问


  - https://leetcode.cn/problems/previous-permutation-with-one-swap/
    - 求小于当前排列的最大排列
    - 从右向左找到第一个逆序对，左边的就是要交换的元素，用右侧的最大值交换，然后将该位置右侧降序排序。本题要求只交换一次，所以不需要排序

## 20230419
- https://www.nowcoder.com/questionTerminal/09066b2c010f4218adb1a1db42dbb236