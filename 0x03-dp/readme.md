# dp

## 线性dp

- [0x00-合唱队形](https://www.luogu.com.cn/problem/P1091)

- [0x01-删数 - 洛谷](https://www.luogu.com.cn/problem/P2426)

- [0x02-饥饿的奶牛 - 洛谷](https://www.luogu.com.cn/problem/P1868)
  
  - dp[i]为前i个区间的最优值
  
  - 排序 + 线性dp + 二分
  
  - 1

- [0x03-[NOIP2000 提高组] 乘积最大 - 洛谷](https://www.luogu.com.cn/problem/P1018)

- [0x04-路径计数2 - 洛谷](https://www.luogu.com.cn/problem/P1176)

- [0x05-[NOIP2008 普及组] 传球游戏 - 洛谷](https://www.luogu.com.cn/problem/P1057)
  
  - <mark>以传球次数作为阶段</mark>

- [0x07-最大正方形 - 洛谷](https://www.luogu.com.cn/problem/P1387)

- [0x08-最大约数和 - 洛谷](https://www.luogu.com.cn/problem/P1734)
  
  - <mark>测试用例是对的但是通不过。。。</mark>

## 背包dp

- [0x00-精卫填海 - 洛谷](https://www.luogu.com.cn/problem/P1510)
  
  - 0-1背包

- [0x01-[USACO18OPEN] Talent Show G - 洛谷](https://www.luogu.com.cn/problem/P4377)
  
  - <mark>0-1分数规划不会</mark>
  
  - <mark>没做出来</mark>

- [0x02-C - Tak and Cards](https://atcoder.jp/contests/arc060/tasks/arc060_a)
  
  - 0-1背包

- 总结
  
  - 如果限制条件是必须大于等于W， 那么第二维可以开到W，对于大于W的情况可以合并到等于W的情况上来

## 树形dp

### 资料

### 题单

- [0x2 树形dp - 题单 - 洛谷](https://www.luogu.com.cn/training/13994)
- [Problem - 161D - Codeforces](https://codeforces.com/problemset/problem/161/D)
  - <mark>思路特别好的树形dp</mark>
  - 又添加了一维作为额外的状态来做，看懂了之后感觉不难

### 总结

- 对于题目中树的边没有方向的，选哪个节点当做根节点都无所谓；否则当处理当前节点时， 不但要考虑子树的贡献，还要考虑祖先的贡献。目前对于第二种，可以使用两次dfs先求子树的贡献，第二次dfs求祖先的贡献。一种思路就是判断一组相邻的节点，看以这两个节点作为根节点时，最后结果有没有差异

- 第二种情况原来是换根dp或者二次扫描法

### 题目

- [0x00-最大子树和 - 洛谷](https://www.luogu.com.cn/problem/P1122)

- [0x01-战略游戏 - 洛谷](https://www.luogu.com.cn/problem/P2016)

- [0x02-[HAOI2009] 毛毛虫 - 洛谷](https://www.luogu.com.cn/problem/P3174)
  
  - 思路肯定对，但是有几个用例通不过
  
  - 代码中使用不同的根节点结果不一样。。。
  
  - 解决了，原因在于没有加上父节点

- [0x03-Choosing Capital for Treeland - 洛谷](https://www.luogu.com.cn/problem/CF219D)

- [0x04-[POI2008] STA-Station - 洛谷](https://www.luogu.com.cn/problem/P3478)

- [0x05-[USACO10MAR] Great Cow Gathering G - 洛谷](https://www.luogu.com.cn/problem/P2986)

- [0x06-[NOI2011] 道路修建 - 洛谷

## 单调队列优化

- [0x00-[USACO11OPEN]Mowing the Lawn G - 洛谷](https://www.luogu.com.cn/problem/P2627)
  
  - <mark>[题解](https://www.luogu.com.cn/problem/solution/P2627)</mark>

- [0x01-[USACO11OPEN]Mowing the Lawn G - 洛谷](https://www.luogu.com.cn/problem/P2627)
  
  - <mark>题解的第二种方法，没做出来</mark>

- [0x02-烽火传递](https://loj.ac/p/10180)
  
  - 单调队列优化模板

- [0x03](https://loj.ac/p/10176)
  
  - 单调队列 + 前缀和

## 状压dp

## 哈密尔顿路径类问题

- `dp[i][j]`表示经过i代表的节点，并且最后一个节点是j的状态下的最短路径。

- [91. 最短Hamilton路径 - AcWing题库](https://www.acwing.com/problem/content/description/93/)
  
  - 很好的状压dp问题，状压的是一个集合的子集，即那些选中了，哪些没选中。还需要一个状态标记这个子集中最后选中的元素
  
  - 不会

- [最短汉密尔顿回路](https://www.nowcoder.com/exam/test/66856352/detail?pid=16516564)
  
  - 计算回路时的状态转移方程是一样的，最后还需要组合一下
  
  - 对于每个状态`i`，其都有一个对应的状态`mask`，除了第一个节点相同外，其余的节点进行异或运算全是1，然后枚举`i和mask`的每一位，作为这个回路的最后组成部分，那么这条回路的长度就是`dp[i][j] + dp[mask][k] + edges[j][k]`

## 其他

- [0x00-国王](https://loj.ac/p/10170)
  
  - 按行状压dp板子题

- [0x01-牧场的安排](https://loj.ac/p/10171)
  
  - 按行状压板子题

- [0x02-吃奶酪 - 洛谷](https://www.luogu.com.cn/problem/P1433)
  
  - 自己做出来的状压dp，和汉密尔顿路径问题相似，难点在于dp的初始状态是什么，这个题需要遍历每个位置作为第一个到达的位置，然后才开始进行dp
  
  - 是一个子集排列问题
  
  - <mark>最好还需要巩固</mark>

- [杀死所有怪物的最短时间](https://leetcode.cn/problems/minimum-time-to-kill-all-monsters/)
  
  - <mark>子集排列问题也不一定必须要有第二维</mark>
  
  - 需不需要第二维要看状态转移方程中和上一个状态的最后一个元素有关没关，有关的话就需要第二维，否则不需要。对于这个题来说，不需要知道上个状态的最后一个元素是谁，所以就不用第二维了
  
  - 其实我们在进行状态转移的时候，会遍历这个状态所有的`1`，每次转移都是以不同的 `1`作为最后一个元素，默认就是有序的

- [Most-Powerful](https://ac.nowcoder.com/acm/problem/15832)
  
  - <mark>感觉思路对了，但是没通过</mark>
  
  - 测试用例过了

- [德玛西亚万岁](https://ac.nowcoder.com/acm/problem/15034)
  
  - 和上一个题一样。。。服了，还看不到测试用例

- [0x03-[USACO06NOV]Corn Fields G - 洛谷](https://www.luogu.com.cn/problem/P1879)
  
  - 和德玛西亚一样的题，那个就通不过，我服了

- [完成任务的最少工作时间段](https://leetcode.cn/problems/minimum-number-of-work-sessions-to-finish-the-tasks/)
  
  - <mark>很好的状压dp题目， 枚举状态的子集</mark>
  
  - 前面做的都是枚举每个状态的每一位，这个是枚举状态的所有子集
  
  - ```cpp
    int subset = mask;
    while(subset > 0) {
        ...
        subset = (subset - 1) & mask;
    }
    ```

- [0x04-U - Grouping](https://atcoder.jp/contests/dp/tasks/dp_u)
  
  - 和上一个题思路一样的， 枚举状态的子集

- [枚举子集](https://leetcode.cn/problems/distribute-repeating-integers/)
  
  - <mark>还没写</mark>

- [好子集的数目](https://leetcode.cn/problems/the-number-of-good-subsets/)
  
  - <mark>还没写</mark>
  - <mark>好难</mark>

- [数组的最大与和](https://leetcode.cn/problems/maximum-and-sum-of-array/)
  
  - <mark>真的是好难啊，没写</mark>

- [字母矩阵_牛客笔试题_牛客网](https://www.nowcoder.com/questionTerminal/0f82611d55dd4c88b6e5367c418d075d?answerType=1&f=discussion)
  
  - <mark>想到了二维前缀和，但是没想到二分，不太应该</mark>
  
  - 以后和最大最小值有关的都要考虑一下二分搜索
