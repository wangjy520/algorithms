/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int mod = 1e5 + 3;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> nums(n, vector<int>(n, 0));
	for(int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		nums[a - 1][b - 1] = 1;
	}

	if(nums[0][0] == 1) {
		cout << 0 << '\n';
		return 0;
	}

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(i == 1 && j == 1) {
				dp[i][j] = 1;
				continue;
			}
			if(nums[i - 1][j - 1] == 1) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
			}
		}
	}
	cout << dp[n][n] << '\n';

	


	return 0;
}