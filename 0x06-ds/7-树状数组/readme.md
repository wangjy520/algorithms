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


## 资料
- https://www.luogu.com.cn/blog/kingxbz/shu-zhuang-shuo-zu-zong-ru-men-dao-ru-fen
## 总结
- 有4种用法
    - 单点修改 + 区间查询
    - 区间修改 + 单点查询
    - 区间修改 + 单点查询
    - 区间最值
- 对于树状数组来说，查询操作就是求前缀和的操作，对于前两种用法，区别就在于对于树状数组的初始化不同