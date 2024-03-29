# 一些有用的小结论&tips
- 给定一个区间`[l, r]`，包含下标为`k`的子区间的个数为`(k - l + 1) * (r - k + 1)`
- 给定一个无序的序列，规定只能交换相邻元素，那么将数组变为有序的最少交换次数就是整个数组的逆序对数目
- 可以用树状数组 + 二分查找整个序列中第k大的数字，为每个数字维护计数值不是1就是0，找到最小的i使得`a[i]`的前缀和等于k
- C++中cin只能读取不包含空格的字符串，可以使用`getline(cin, s);`的方式读取空格，以回车作为结束符
- C++中使用自定义函数的优先队列
    ```cpp
    auto cmp = [&](int i, int j) -> bool {
        return a[i] > a[j];
    };
    priority_queue<int, vector<int>, decltype(cmp)> h(cmp);
    // 这是小顶堆的
    ```
- 有些思路就是自己像的那样，只是麻烦了一点
- 一个有序数组，每个元素只能+1 or -1，将数组的所有元素都变成相等时，具有最小操作次数的是这个数组的中位数，即便数组长度是偶数，也可以直接求中位数
- C++中的函数`substr(start, length)`，第一个参数是开始位置，第二个是子串长度
- C++中的三目运算符后两个值必须是同一个类型的
- C++在读入数据的时候不能用int类型接收字符
- C++输入指定位数的小数:`cout << fixed << setprecision(n) << ans << '\n'`，n指定了小数点后面的位数
- C++中的double类型不一定是64位的，得看编译器，如果编译器中double是32位的，那么数字很大的时候可能会出错
- 百度笔试第一题，使用C++的double不通过，同样的逻辑使用Java的double就通过了，很奇怪
- C++中的cin遇到空格就停止输入，如果一个字符串中有空格，则需要使用`getline(cin, s)`进行输入