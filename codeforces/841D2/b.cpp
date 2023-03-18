//
// Created by Wangjy.
// Modulus should always be taken after every multiply operation to avoid the overflow.
// https://codeforces.com/blog/entry/110630
//
#include<bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;

void solve() {
    long long n;
    cin >> n;
    cout << ((((n*(n+1))%mod)*(4*n-1))%mod*337)%mod << '\n';
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
