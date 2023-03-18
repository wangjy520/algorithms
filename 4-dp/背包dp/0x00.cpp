/* 
** Created by Wangjy.
** https://www.luogu.com.cn/problem/P1510
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int V, n, W;
	cin >> V >> n >> W;
	vector<int> v(n), w(n);
	for(int i = 0;i < n;i++) {
		cin >> v[i] >> w[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(V + 1, 0x3f3f3f3f));
	for(int j = 0;j <= V;j++) {
		dp[0][j] = 0;
	}
	for(int i = 1;i <= n;i++) {
		for(int j = V;j >= 0;j--) {
			if(j >= v[i - 1]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
			}
			else {
				break;
			}
		}
	}
	if(dp[n][V] != 0x3f3f3f3f) {
		cout << (W - dp[n][V]) << '\n';
	}
	else {
		cout << "Impossible" << '\n';
	}
	


	return 0;
}