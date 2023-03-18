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
const LL inf = -1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(auto& i : a) {
		cin >> i;
	}
	vector<vector<LL>> dp(n + 1, vector<LL>(m + 1, inf));
	dp[0][0] = 0;
	for(int i = 1;i <= n;i++) {
		dp[i][0] = 0;
		for(int j = 1;j <= m;j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1LL * j * a[i - 1]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	cout << dp[n][m] << '\n';

	return 0;
}