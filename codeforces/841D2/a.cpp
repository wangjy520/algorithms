//
// Created by Wangjy.
//
#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long m = 1;
    // vector<long long> a(n);
    for(int i = 0;i < n;i++) {
        long long a;
        cin >> a;
        m *= a;
    }
    cout << 2022 * (m + n - 1) << '\n';
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
