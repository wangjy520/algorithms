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

const int mod = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> w(n);
	for(int i = 0;i < n;i++) {
		cin >> w[i];
	}

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)), res(n + 1, vector<int>(m + 1, 0));

	dp[0][0] = 1;
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j <= m;j++) {
			dp[i][j] = dp[i - 1][j];
			res[i][j] = dp[i][j];
			if(j >= w[i - 1]) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j - w[i - 1]]) % mod;
			}
		}
	}
	// vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
	// f[0][0] = 1;
	// for(int i = 1;i <= n;i++) {
	// 	for(int j = 0;j <= m;j++) {
	// 		if(j >= w[i - 1]) {
	// 			f[i][j] = f[i - 1][j - w[i - 1]];
	// 			dp[i][j] = (dp[i][j] - f[i][j] + mod) % mod;
	// 		}
	// 		dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
	// 	}
	// }
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			cout << ((dp[n][m] - dp[i - 1][m - w[i - 1]]) % 10);
		}
		cout << '\n';
	}

	return 0;
}