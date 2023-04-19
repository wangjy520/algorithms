# 树状数组
- [0x06](https://www.luogu.com.cn/problem/P4939)
    - 使用树状数组维护差分数组
    - 树状数组的模板代码是一样的，但是插入时的逻辑需要自己搞定
- [0x07](https://www.luogu.com.cn/problem/P2367)
    - 用差分数组就好，没必要用树状数组
- [0x08](https://www.luogu.com.cn/problem/P1637)
    - 枚举中间数 + 树状数组
- [0x09](https://www.luogu.com.cn/problem/P3372)
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
- [0x0a](https://www.luogu.com.cn/problem/P2357)
    - 区间修改 + 区间查询
    - 比线段树写着更简洁
- [0x0b](https://www.luogu.com.cn/problem/P6225)
    - 对于异或操作的单点修改 + 区间查询，但是需要分析一下，抽象出思路，来使用树状数组解决
    - 异或操作又名不进位加法，因此相对于加法操作来说是一样的。加法的逆操作为减法，而异或的逆操作还是异或，甚至更简单了
    - 对于本题，先分析区间`[l, r]`中每个数字的出现次数，区间长度为`len = r - l + 1`，每个数字的出现次数分别是`n, 2 * (n - 1)...`，
    当len为偶数时，这些次数都是偶数，最后结果为0；否则就是第奇数个出现次数为奇数。因此用两个树状数组分别维护奇数位和偶数位的异或和即可
- [0x0c](https://www.luogu.com.cn/problem/P1774)
    - 转换成求逆序对
- https://www.acwing.com/problem/content/245/
    - 非常好的题目
    - 树状数组 + 二分查找
    - 具体思路见《算法竞赛进阶指南》第209页
- [0x0d](https://atcoder.jp/contests/abc174/tasks/abc174_f)
    - 离线 + 树状数组
    - 用树状数组统计每个颜色出现的最后位置（该位置为1），最后查询的时候也是个求连续和的操作。由于要依次处理，所以必须是离线算法，按照右端点排序。这里树状数组对应的原数组非0即1，表示出没出现
- https://lightoj.com/problem/curious-robin-hood
    - 板子题
- [0x0e](https://www.spoj.com/problems/MATSUM/)
    - 二维树状数组板子题
    - 特别注意这里不能使用`for(;i <= n;i += lowbit(i))`这种循环方式了，第一重循环没问题，但是第二维就有问题了
- [0x10](https://www.luogu.com.cn/problem/P2345)
    - 所求的表达式中前后两项都是变化的，因此需要固定一个。对于每个位置，只考虑其前面且叫声更小的位置，那么第一项就成了定值。正反分别统计两次即可
    - 这里的树状数组用作统计符合条件的元素个数
- [0x11](https://loj.ac/p/130)
    - 板子
- [0x12](https://loj.ac/p/131)
    - 板子
- [0x13](https://loj.ac/p/132)
    - 板子
## 资料
- https://www.luogu.com.cn/blog/kingxbz/shu-zhuang-shuo-zu-zong-ru-men-dao-ru-fen
## 总结
- 有好多种种用法
    - 单点修改 + 区间查询
    - 区间修改 + 单点查询
    - 区间修改 + 单点查询
    - 区间最值
    - 配合二分找top-K
- 对于树状数组来说，查询操作就是求前缀和的操作，对于前两种用法，区别就在于对于树状数组的初始化不同
- 根据《算法竞赛进阶指南》，在单点修改 + 区间查询的操作中，树状数组中维护的是原始的数组的信息；而对于区间修改 + 单点查询的操作中，树状数组中维护的实际上是原始数组的变化数组。在初始化的时候可以看做是对原始数组全为0的操作