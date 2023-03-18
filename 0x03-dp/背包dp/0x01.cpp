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

	int n, W;
	cin >> n >> W;
	vector<int> w(n), t(n);
	for(int i = 0;i < n;i++) {
		cin >> w[i] >> t[i];
	}	

	vector<vector<pii>> dp(n + 1, vector<pii>(W + 1));
	dp[0][0] = make_pair(0, 0);
	cout << "here" << '\n';
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j <= W;j++) {
			dp[i][j] = dp[i - 1][j];
			int a = t[i - 1], b = w[i - 1];
			if(j - w[i - 1] > 0) {
				a += dp[i - 1][j - w[i - 1]].first;
				b += dp[i - 1][j - w[i - 1]].second;	
			}
			if((1000LL * a / b) > (1000LL * dp[i][j].first / dp[i][j].second)) {
				dp[i][j] = make_pair(a, b);
			}
		}
	}
	
	int x = dp[n][W].first, y = dp[n][W].second;
	cout << x << " " << y << '\n';
	// cout << (y == 0 ? 0 : 1000LL * x / y) << '\n';

	return 0;
}