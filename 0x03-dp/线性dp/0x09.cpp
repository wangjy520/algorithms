#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	dp[0][0] = 1;
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j <= k;j++) {
			for(int a = 1;a <= m;a++) {
				if(j - a >= 0) {
					dp[i][j] = (dp[i][j] + dp[i - 1][j - a]) % mod;
				}
			}
		}
	}
	int res = 0;
	for(int i = 0;i <= k;i++) {
		res = (res + dp[n][i]) % mod;
	}
	cout << res << '\n';

	return 0;
}