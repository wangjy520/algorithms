/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	vector<int> sum(n);
	for(int i = 0;i < n;i++) {
		cin >> coins[i] >> sum[i];
	}

	vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));
	dp[0][0] = true;
	for(int i = 1;i <= n;i++) {
		for(int j = x;j >= 0;j--) {
			for(int k = 0;k <= sum[i - 1];k++) {
				if(j - k * coins[i - 1] >= 0) {
					dp[i][j] = dp[i][j] || dp[i - 1][j - k * coins[i - 1]];
				}
			}
		}
	}
	cout << (dp[n][x] ? "Yes" : "No") << '\n';


	return 0;
}