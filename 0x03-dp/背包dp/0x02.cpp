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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a;
	cin >> n >> a;
	vector<int> nums(n);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
	}

	int m = n * a;
	vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n + 1, vector<long long>(m + 1, 0)));
	dp[0][0][0] = 1;
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j <= n;j++) {
			for(int k = 0;k <= m;k++) {
				dp[i][j][k] += dp[i - 1][j][k];
				if(k - nums[i - 1] >= 0 && j > 0) {
					dp[i][j][k] += dp[i - 1][j - 1][k - nums[i - 1]];
				}
			}
		}
	}
	long long res = 0;
	for(int i = a, j = 1;j <= n;i += a, j++) {
		res += dp[n][j][i];
	}
	cout << res << '\n';

	return 0;
}