//
// Created by Wangjy.
// 思路全对了
// https://codeforces.com/blog/entry/110630
//
#include<bits/stdc++.h>

using namespace std;
vector<int> s;

void solve() {
    long long n;
    cin >> n;
    vector<int> a(n), m(2 * n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    long long cnt = 0;
    int cur = 0;
    m[cur]++;
    for(int i = 0;i < n;i++) {
        cur ^= a[i];
        for(long long j = 0;j * j < 2 * n;j++) {
            if((cur ^ (j * j)) < 2 * n) {
                cnt += m[cur ^ (j * j)];
            }
        }
        m[cur]++;
    }
    cout << ((n * (n + 1) / 2) - cnt) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
