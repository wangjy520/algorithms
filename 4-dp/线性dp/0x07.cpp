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



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> nums(n, vector<int>(m));
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			cin >> nums[i][j];
		}
	}
	int res = 0;
	vector<vector<int>> dp(n, vector<int>(m, 0));
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			if(nums[i][j] == 1) {
				dp[i][j] = 1;
				int c1 = 0, c2 = 0, c3 = 0;
				if(i > 0 && j > 0)
					c1 = dp[i - 1][j - 1];
				for(int k = i - 1;k >= 0;k--) {
					if(nums[k][j] == 1)
						c2++;
					else 
						break;
				}
				for(int k = j - 1;k >= 0;k--) {
					if(nums[i][k] == 1)
						c3++;
					else 
						break;
				}
				dp[i][j] = min(c1, min(c2, c3)) + 1;
				res = max(res, dp[i][j]);
			}
			// cout << dp[i][j] << " ";
		}
		// cout << "\n";
	}
	cout << res << '\n';


	return 0;
}