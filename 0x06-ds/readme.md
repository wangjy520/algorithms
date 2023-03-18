# 数据结构

## 链表

- [约瑟夫问题 - 洛谷](https://www.luogu.com.cn/problem/P1996)
  
  - 链表模拟

- [队列安排 - 洛谷](https://www.luogu.com.cn/problem/P1160)
  
  - 双向链表模拟
  
  - 没通过，内存问题

## 栈

- [后缀表达式 - 洛谷](https://www.luogu.com.cn/problem/P1449)
  
  - 毫无疑问的栈

- [表达式括号匹配 - 洛谷](https://www.luogu.com.cn/problem/P1739)
  
  - 经典括号匹配问题

- [[NOIP2013 普及组] 表达式求值 - 洛谷](https://www.luogu.com.cn/problem/P1981)
  
  - 看了题解
  
  - 一个栈保存数字，一个栈保存操作符。依次分析每个字符是数字还是操作符，操作符入栈时注意要保持从栈底到栈顶的优先级必须是严格递增的

## 队列

- [[NOIP2010 提高组] 机器翻译 - 洛谷](https://www.luogu.com.cn/problem/P1540)
  
  - 队列模拟

## 并查集

- [0x00-修复公路 - 洛谷](https://www.luogu.com.cn/problem/P1111)
  
  - 并查集判断图是否连通

- [0x01-[NOIP2010 提高组] 关押罪犯 - 洛谷](https://www.luogu.com.cn/problem/P1525)
  
  - <mark>带扩展域的并查集</mark>

- [0x02-[JSOI2008] 星球大战 - 洛谷](https://www.luogu.com.cn/problem/P1197)
  
  - 并查集判断是否连通
  
  - 将删除节点转换为添加节点的操作，逆序进行

- [0x03-[NOI2015] 程序自动分析 - 洛谷](https://www.luogu.com.cn/problem/P1955)
  
  - 离散化 + 并查集

- [0x04-[NOI2002] 银河英雄传说 - 洛谷](https://www.luogu.com.cn/problem/P1196)
  
  - <mark>带边权的并查集，新思路</mark>
  
  - 详情见《算法竞赛进阶指南》PDF206页
  
  - 只使用了路径压缩，而没有使用按秩合并

- [0x05](https://loj.ac/p/2129)

- [0x06-亲戚 - 洛谷](https://www.luogu.com.cn/problem/P1551)
  
  - 板子

- [0x07-朋友 - 洛谷](https://www.luogu.com.cn/problem/P2078)
  
  - [普通解法](https://www.luogu.com.cn/record/102293114)
  
  - [在合并的过程中直接统计](https://www.luogu.com.cn/record/102293214)
  
  - <mark>注意在合并的过程中1的根节点可能不再是1了。。。</mark>

- [0x08-一中校运会之百米跑 - 洛谷](https://www.luogu.com.cn/problem/P2256)
  
  - 板子

- [0x09-集合 - 洛谷](https://www.luogu.com.cn/problem/P1621)
  
  - 线性筛 + 并查集

- [0x0a-村村通 - 洛谷](https://www.luogu.com.cn/problem/P1536)

- [0x0b-家谱 - 洛谷](https://www.luogu.com.cn/problem/P2814)
  
  - 在需要指定特殊的根节点时不能按秩合并，否则可能就不是指定的根节点了

- [0x0c-[BOI2003]团伙 - 洛谷](https://www.luogu.com.cn/problem/P1892)
  
  - <mark>带扩展域的并查集</mark>

- [0x0d-[POI2005]SKA-Piggy Banks - 洛谷](https://www.luogu.com.cn/problem/P3420)
  
  - <mark>统计连通块的个数，比较难分析，代码不难</mark>
  
  - 有多少个连通块就有多少个根节点，而根节点的`p[x] == x`成立，所以直接统计这个条件成立即可，不需要使用set

- [0x0e-pSort - 洛谷](https://www.luogu.com.cn/problem/CF28B)
  
  - <mark>主要是思路的转换</mark>

- [0x0f-搭配购买 - 洛谷](https://www.luogu.com.cn/problem/P1455)
  
  - 并查集 + 分组背包
  
  - <mark>1e8也能过就离谱的。。</mark>

- [0x10-选学霸 - 洛谷](https://www.luogu.com.cn/problem/P2170)
  
  - <mark>并查集 + 多重背包</mark>

## 二叉堆

- [0x00-【模板】堆 - 洛谷](https://www.luogu.com.cn/problem/P3378)

- [0x01-[NOIP2004 提高组] 合并果子 / [USACO06NOV] Fence Repair G - 洛谷](https://www.luogu.com.cn/problem/P1090)
  
  - 贪心 + 二叉堆

## ST表

- [0x00-【模板】ST 表 - 洛谷](https://www.luogu.com.cn/problem/P3865)

- [0x01-质量检测 - 洛谷](https://www.luogu.com.cn/problem/P2251)

- [0x02-忠诚 - 洛谷](https://www.luogu.com.cn/problem/P1816)

- [0x03-[USACO07JAN] Balanced Lineup G - 洛谷](https://www.luogu.com.cn/problem/P2880)

## 树状数组

- [0x00-【模板】树状数组 1 - 洛谷](https://www.luogu.com.cn/problem/P3374)

- [0x01-逆序对 - 洛谷](https://www.luogu.com.cn/problem/P1908)
  
  - <mark>离散化树状数组，不知道哪有问题</mark>

- [0x03-【模板】树状数组 2 - 洛谷](https://www.luogu.com.cn/problem/P3368)
  
  - 支持区间修改和单点查询
  
  - <mark>与普通方式的不同点在于需要特别对数组进行初始化</mark>
  
  - <mark>或者以添加元素的方式进行初始化也行，即区间长度为1</mark>

- [0x04-[CQOI2006]简单题 - 洛谷](https://www.luogu.com.cn/problem/P5057)
  
  - 区间修改和单点查询

- [0x05-统计和 - 洛谷](https://www.luogu.com.cn/problem/P2068)
  
  - 树状数组模板题

## 线段树

- [0x00-GSS3 - Can you answer these queries III - 洛谷](https://www.luogu.com.cn/problem/SP1716)
  
  - 最大子段和问题
  
  - <mark>不知道哪里不对</mark>

- [0x01-【模板】线段树 1 - 洛谷](https://www.luogu.com.cn/problem/P3372)
  
  - 区间修改 + 区间查询模板
  
  - <mark>特别注意对子节点懒标记的更新，即push_down函数</mark>
