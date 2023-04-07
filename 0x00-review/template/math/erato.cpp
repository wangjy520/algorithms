#include<bits/stdc++.h>
using namespace std;

/**
 * 埃氏筛求1~n的所有质数
 * 时间复杂度：O(n loglogn)
*/
vector<int> solve(int n) {
    vector<int> p;
    vector<bool> v(n + 1, true);
    for(int i = 2;i <= n;i++) {
        if(v[i]) {
            p.push_back(i);
            for(int j = i * i;j <= n;j += i) {
                v[j] = false;
            }
        }
    }
    return p;
}