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
	vector<vector<int>> dp(m + 1, vector<int>(n, 0));
	dp[0][0] = 1;
	for(int i = 1;i <= m;i++) {
		for(int j = 0;j < n;j++) {
			dp[i][j] = dp[i - 1][(j - 1 + n) % n] + dp[i - 1][(j + 1) % n];
		}
	}
	cout << dp[m][0] << '\n';
	


	return 0;
}