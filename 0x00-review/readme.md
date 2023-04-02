# review
- [1039-多边形三角形的最优剖分](https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/)
    - `dp[i][j]`为从顶点`i`到顶点`j`的最小值，以i-j的线段为底边， 枚举每个底边对应的顶点
    - `dp[i][j] = min{dp[i][k] + dp[k][j] + a[i] * a[j] * a[k]}, i < k <= j`
- https://ac.nowcoder.com/acm/problem/13134
  - 最长上升子序列变形
  - 统计从左开始最长上升连续子序列的长度以及从右侧开始最长连续下降子序列的长度，枚举每个断点，如果`a[i + 1] - a[i - 1] >= 2`，可以修改断点`i`，更新答案为`res = max(res, left[i - 1] + right[i + 1] + 1)`
- https://leetcode.cn/contest/biweekly-contest-100/problems/distribute-money-to-maximum-children/
  - 智商题，贪心，先给每个人分一颗糖，再分剩下的糖。注意有很多特殊情况要考虑到
- https://leetcode.cn/problems/numbers-with-repeated-digits/
  - 逆向思维 + 数位dp
  - 数位dp采用记忆化搜索完成，求出没有重复数字的数字个数，然后减掉即可
  - 对于数位dp，`is_num`表示上一个位置是否为一个数字，决定当前位置所填数字的下界，即从0开始还是从1开始；`is_limit`表示当前位置是否受到限制，决定了当前位置所填数字的上界，即是否能取到9；第一个参数为`i`，表示当前的位置；另一个参数一般是上一个及之前位置的状态或者对答案做出的贡献，这样当`i == m`的时候，这个参数恰好就是前面所有位置的总贡献，累加到答案中即可
- https://leetcode.cn/problems/binary-tree-inorder-traversal/
  - 非递归中序遍历：root表示当前子树的根节点，st中保存等待遍历的节点。如果当前的root存在左子树，那么一直遍历到左子树的最左下端，并将经过的节点全部入栈；否则就从栈中取出一个节点遍历，并将指针root指向该节点的右子树
  - 莫里斯中序遍历：还是使用root指针作为当前遍历到的节点，如果存在左子树，则找到左子树中最右边的节点（最后被访问到的），直到为空或者等于root，利用了空闲指针代替栈保存下一个要访问的节点；如果等于root表示当前左子树遍历完成，输出root->val, root指向右子树；否则将该指针指向root，root=root->left；如果没有左子树就直接输出然后指向右子树
- https://ac.nowcoder.com/acm/problem/20491
  - 数位dp
  - 分别统计每个数字出现的次数
- https://www.luogu.com.cn/problem/P3372
    - 区间修改 + 区间查询
    - 使用两个数组维护树状数组
    ```cpp
    vector<int> c(n + 1, 0), d(n + 1, 0);

    int lowbit(int x) {
        return x & (-x);
    }

    void add(int i, int x) {
        for(int j = i;j <= n;j += lowbit(j)) {
            c[j] += x;
            d[j] += x * (i - 1);
        }
    }

    int sum(int i) {
        int res = 0;
        for(int j = i;j > 0;j -= lowbit(j)) {
            res += i * c[j] - d[j];
        }
        return res;
    }

    int sum(int i, int j) {
        return sum(j) - sum(i - 1);
    }
    ```
    - 暂时看不太懂，先背下来再说吧
    - 注意这种方式中，树状数组初始化的方式是作为差分数组进行的。而初始化差分数组有两种方式：
    ```cpp
    1、add(i, a[i] - a[i - 1]);
    2、add(i, a[i]), add(i + 1, -a[i]);
    ```
    - 两种方式是一样的
- https://www.acwing.com/problem/content/245/
    - 非常好的题目
    - 树状数组 + 二分查找
    - 具体思路见《算法竞赛进阶指南》第209页
- https://leetcode.cn/problems/queue-reconstruction-by-height/
  - 暴力
- https://www.nowcoder.com/questionTerminal/09066b2c010f4218adb1a1db42dbb236
  - 想不明白的贪心
- https://leetcode.cn/problems/non-decreasing-subsequences/
  - 精妙的去重操作
  - https://leetcode.cn/problems/non-decreasing-subsequences/solution/di-zeng-zi-xu-lie-by-leetcode-solution/
- https://leetcode.cn/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
  - 折半枚举 + 二分查找
- https://leetcode.cn/problems/minimum-reverse-operations/
  - BFS + set优化
  - 大体思路是在BFS求最短路的同时判断当前节点应该更新到哪些节点。以前做的都是提前建好图再BFS
  - 求最小可以考虑使用BFS求最短路
  - https://leetcode.cn/problems/minimum-reverse-operations/solution/bfstiao-yue-you-xi-jia-qiang-ban-by-tsre-juxn/
  - 想到了BFS，但是建图的时候会TLE。原因在于有很多位置被重复的访问，而这些位置是不会再次被更新的。因为当作图来考虑的话，边权都是1，所以使用普通的BFS就能够更新了，也就是一旦某些位置被访问过了，那么就不需要再次访问