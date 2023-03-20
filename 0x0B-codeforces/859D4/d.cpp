/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	vector<int> pre(n + 1, 0);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		pre[i + 1] = (pre[i] ^ (a[i] % 2));
	}
	for(int i = 0;i < q;i++) {
		int l, r, k;
		cin >> l >> r >> k;
		int len = r - l + 1;
		if(len % 2 == 1 && k % 2 == 1) {
			cout << ((1 ^ pre[l - 1] ^ pre[n] ^ pre[r]) == 1 ? "Yes" : "No") << '\n';
		}
		else {
			cout << ((0 ^ pre[l - 1] ^ pre[n] ^ pre[r]) == 1 ? "Yes" : "No") << '\n';	
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}