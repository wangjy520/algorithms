# 树形dp

## 资料

- ## 题单

- [0x2 树形dp - 题单 - 洛谷](https://www.luogu.com.cn/training/13994)

## 总结

- 对于题目中树的边没有方向的，选哪个节点当做根节点都无所谓；否则当处理当前节点时， 不但要考虑子树的贡献，还要考虑祖先的贡献。目前对于第二种，可以使用两次dfs先求子树的贡献，第二次dfs求祖先的贡献。一种思路就是判断一组相邻的节点，看以这两个节点作为根节点时，最后结果有没有差异

- 第二种情况原来是换根dp或者二次扫描法

## 题目

- [0x00-最大子树和 - 洛谷](https://www.luogu.com.cn/problem/P1122)

- [0x01-战略游戏 - 洛谷](https://www.luogu.com.cn/problem/P2016)

- [0x02-[HAOI2009] 毛毛虫 - 洛谷](https://www.luogu.com.cn/problem/P3174)
  
  - <mark>思路肯定对，但是有几个用例通不过</mark>
  
  - 代码中使用不同的根节点结果不一样。。。
  
  - 解决了，原因在于没有加上父节点

- [0x03-Choosing Capital for Treeland - 洛谷](https://www.luogu.com.cn/problem/CF219D)

- [0x04-[POI2008] STA-Station - 洛谷](https://www.luogu.com.cn/problem/P3478)

- [0x05-[USACO10MAR] Great Cow Gathering G - 洛谷](https://www.luogu.com.cn/problem/P2986)

- [0x06-[NOI2011] 道路修建 - 洛谷](https://www.luogu.com.cn/problem/P2052)
