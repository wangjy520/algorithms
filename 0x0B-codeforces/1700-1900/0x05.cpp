/* 
** Created by Wangjy.
** https://codeforces.com/problemset/problem/467/C
** 线性dp
** easy
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

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	vector<LL> pre(n + 1, 0);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		pre[i + 1] = pre[i] + a[i];
	}
	vector<vector<LL>> dp(n, vector<LL>(k + 1, -1));
	dp[m - 1][1] = pre[m];
	for(int i = m;i < n;i++) {
		for(int j = 1;j <= k;j++) {
			dp[i][j] = dp[i - 1][j];
			if(dp[i - m][j - 1] != -1) {
				dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + pre[i + 1] - pre[i - m + 1]);
			}
			else {
				dp[i][j] = max(pre[i + 1] - pre[i - m + 1], dp[i][j]);
			}
		}
	}
	cout << dp[n - 1][k] <<'\n';

	return 0;
}