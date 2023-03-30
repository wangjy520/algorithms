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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	vector<int> dp(n, 1);
	for(int i = 1;i < n;i++) {
		if(a[i] > a[i - 1] / 2) {
			dp[i] = dp[i - 1] + 1;
		}
	}
	int ans = 0;
	for(int i = k;i < n;i++) {
		if(dp[i] >= k + 1) {
			ans++;
		}
	}
	cout << ans << '\n';
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