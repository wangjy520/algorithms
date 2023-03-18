/* 
** Created by Wangjy.
** https://www.luogu.com.cn/problem/P1586
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> dp(n + 1, vector<int>(5, 0));
	dp[0][1] = 1;
	for(int i = 1;i <= n;i++) {
		int s = sqrt(i);
		if(s * s == i) {
			dp[i][1] = 1;
		}
		int cnt = 1;
		while(i - cnt * cnt >= 0) {
			for(int k = 1;k <= 3;k++) {
				dp[i][k + 1] = dp[i - cnt * cnt][k];
			}
			cnt++;
		}
	}
	int res = 0;
	for(int i = 1;i <= 4;i++) {
		res += dp[n][i];
	}
	cout << res << '\n';
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