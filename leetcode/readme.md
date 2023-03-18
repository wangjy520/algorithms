# leetcode

- [1798](https://leetcode.cn/problems/maximum-number-of-consecutive-values-you-can-make/)
  
  - <mark>构造</mark>

- [打家劫舍](https://leetcode.cn/problems/house-robber-iv/)
  
  - <mark>二分 + dp</mark>
  
  - 二分 + 贪心

- [字符串解码](https://leetcode.cn/problems/decode-string/)
  
  - <mark>栈</mark>

- [礼盒的最大甜蜜度](https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/)
  
  - <mark>二分答案</mark>
  
  - check函数的思路比较新。普通的思路是固定k，看能不能满足mid的要求，这个是固定mid，看能不能满足k的要求

- [移除子树后的最大高度](https://leetcode.cn/problems/height-of-binary-tree-after-subtree-removal-queries/)
  
  - <mark>两次dfs，有点类似于换根dp</mark>
  
  - <mark>dfs + 时间戳</mark>，利用dfs将序列转换成线性的，删除一个子树就相当于是删除了线性序列中的一个连续部分，剩下的就是一个前缀和后缀，对前后缀进行预处理后可以直接查询

- [对字母串可执行的最大删除数](https://leetcode.cn/problems/maximum-deletions-on-a-string/)
  
  - 线性dp
  
  - <mark>dp预处理两个字符串的最长公共前缀</mark>

- [删除操作后的最大子段和](https://leetcode.cn/problems/maximum-segment-sum-after-removals/)
  
  - <mark>并查集， 将删除操作转换成合并操作</mark>
  
  - 思路想到了，但是具体细节还没实现

- [修改两个元素的最小分数](https://leetcode.cn/problems/minimum-score-by-changing-two-elements/)
  
  - <mark>构造</mark>

- [循环码排列](https://leetcode.cn/problems/circular-permutation-in-binary-representation/)
  
  - 格雷码

- [两个序列_阿里巴巴笔试题_牛客网](https://www.nowcoder.com/questionTerminal/b65b8b1376d94d4b8d4718ba2f4c0022?answerType=1&f=discussion)
  
  - <mark>巧妙地转化成了最长上升子串的长度问题</mark>

- [至多包含两个不同字符的最长子串](https://leetcode.cn/problems/longest-substring-with-at-most-two-distinct-characters/)
  
  - 双指针
  
  - 求最长就左指针每次移动一次，右指针不断向右；求最短就右指针每次移动一次，左指针不断向右

- [K个不同整数的子数组](https://leetcode.cn/problems/subarrays-with-k-different-integers/)
  
  - <mark>滑动窗口双指针（实际上使用了三个指针，两个标记符合条件的左端点的范围）</mark>
  
  - 因为每个右端点对答案的贡献不只是一个，可能是多个。以前做的都是1个的情况，即要么最短长度，要么最长长度，一个端点只有一个答案

- [保证图可完全遍历](https://leetcode.cn/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/)
  
  - <mark>没想到并查集就挺离谱的，之后自己AC了</mark>

- [统计元音字母序列的个数](https://leetcode.cn/problems/count-vowels-permutation/)
  
  - <mark>矩阵快速幂</mark>

- [找到最小生成树里的关键边和伪关键边](https://leetcode.cn/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/)
  
  - <mark>并查集 + 克鲁斯卡尔  + tarjan求割边</mark>

- [连通两组点的最小成本](https://leetcode.cn/problems/minimum-cost-to-connect-two-groups-of-points/)
  
  - <mark>好题好题</mark>

- [求出最多标记下标](https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices/)
  
  - <mark>二分的思路很好</mark>
  
  - 而且一般来说，二分中的`check`函数都会使用贪心的思路，所以有时候可以将二分改为贪心解决

- [安排邮筒](https://leetcode.cn/problems/allocate-mailboxes/)
  
  - <mark>线性dp + 区间dp预处理</mark>
  
  - 应该能够做出来的，感觉是里面的那个结论没想到，n个房子，其中安排一个邮筒，距离总和最小，此时就要把邮筒放在房子中位数的那个位置

- [统计可以被K整除的下标对数目](https://leetcode.cn/problems/count-array-pairs-divisible-by-k/)
  
  - <mark>数论最大公约数</mark>

- [移除9](https://leetcode.cn/problems/remove-9/)
  
  - <mark>思路清奇到完全想不到</mark>
  
  - <mark>九进制数字</mark>

- [最短超级串](https://leetcode.cn/problems/find-the-shortest-superstring/)
  
  - <mark>状压dp</mark>

- [杀死所有怪物的最短时间](https://leetcode.cn/problems/minimum-time-to-kill-all-monsters/)
  
  - 状压dp

- [下一个数](https://leetcode.cn/problems/closed-number-lcci/)
  
  - <mark>贪心</mark>

- [布尔运算](https://leetcode.cn/problems/boolean-evaluation-lcci/)
  
  - <mark>新奇的区间dp思路</mark>

- [交点](https://leetcode.cn/problems/intersection-lcci/)
  
  - <mark>完全不会</mark>

- [最大矩阵和](https://leetcode.cn/problems/intersection-lcci/)
  
  - <mark>降维，思路很清奇</mark>

- [按位与为零的三元组](https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero/)
  
  - 由于值域很小，转而枚举值域
  
  - <mark>很好的思路</mark>

- [分数到小数](https://leetcode.cn/problems/fraction-to-recurring-decimal/)
  
  - <mark>长除法模拟 + 哈希表记录循环节</mark>
  
  - <mark>分数到小数，如果是无限小数，那么一定是无限循环小数</mark>

- [洗牌算法](https://leetcode.cn/problems/shuffle-an-array/)
  
  - <mark>从没见过</mark>
  
  - [概率相等证明](https://leetcode.cn/problems/shuffle-an-array/solution/wei-rao-li-lun-jing-dian-xi-pai-suan-fa-11ona/)

- [O(1)时间插入删除和获取随机元素](https://leetcode.cn/problems/insert-delete-getrandom-o1/)
  
  - <mark>哈希表 + 随机数</mark>

- [回文链表](https://leetcode.cn/problems/palindrome-linked-list/)
  
  - 修改链表结构

- [把二叉搜索树转换为累加树](https://leetcode.cn/problems/convert-bst-to-greater-tree/)
  
  - <mark>感觉思路也不难想啊。。。</mark>

- [正则表达式匹配](https://leetcode.cn/problems/regular-expression-matching/)
  
  - <mark>虽然自己做出来了但是还不是答案的思路。现在看答案的思路也不很难了</mark>

- [判断二分图](https://leetcode.cn/problems/is-graph-bipartite/)
  
  - 并查集
  
  - DFS || BFS染色判定

- [图中的最长环](https://leetcode.cn/problems/longest-cycle-in-a-graph/)
  
  - <mark>dfs时间戳</mark>
  
  - 自己做出来了其实，就是麻烦了一点

- [统计子树中城市之间最大距离](https://leetcode.cn/problems/count-subtrees-with-max-distance-between-cities/)
  
  - <mark>思路其实也不难</mark>

- [按要求补齐数组](https://leetcode.cn/problems/patching-array/)
  
  - <mark>贪心，思路不错</mark>

- [IPO](https://leetcode.cn/problems/ipo/)
  
  - 堆 + 贪心，把当前能够选择的项目放到堆里面，每次选择最优的
  
  - 思路好

- [员工空闲时间](https://leetcode.cn/problems/employee-free-time/)
  
  - <mark>区间问题，一直不太会</mark>
  
  - <mark>贪心 + 堆</mark>

- [每个人戴不同帽子的方案数](https://leetcode.cn/problems/number-of-ways-to-wear-different-hats-to-each-other/)
  
  - AC了
  
  - 状态压缩动态规划，一看数据范围就可以想到压缩的是谁的状态

- [最小区间](https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/)
  
  - <mark>贪心 + 最小堆</mark>

- [用地毯覆盖后的最少白色砖块](https://leetcode.cn/problems/minimum-white-tiles-after-covering-with-carpets/)
  
  - <mark>状态转移</mark>
  
  - 状态的设计
