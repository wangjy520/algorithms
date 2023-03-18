/* 
** Created by Wangjy.
** https://codeforces.com/problemset/problem/148/E
** 分组背包 + 提前枚举优化
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

	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n);
	vector<vector<int>> pre(n);
	for(int i = 0;i < n;i++) {
		int k;
		cin >> k;
		vector<int> v(k), p(k + 1, 0);
		for(int j = 0;j < k;j++) {
			cin >> v[j];
			p[j + 1] = p[j] + v[j];
		}
		a[i] = v;
		pre[i] = p;
	}

	vector<vector<int>> b(n);
	for(int i = 0;i < n;i++) {
		int len = a[i].size();
		vector<int> v(len + 1, 0);
		for(int k = 0;k <= len;k++) {
			int mx = 0;
			for(int j = 0;j <= k;j++) {
				mx = max(mx, pre[i][j] + pre[i][len] - pre[i][len - k + j]);
			}
			v[k] = mx;
		}
		b[i] = v;
	}

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j <= m;j++) {
			dp[i][j] = dp[i - 1][j];
			int len = a[i - 1].size();
			for(int k = 1;k <= len;k++) {
				if(j - k >= 0)
					dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + b[i - 1][k]);
			}
		}
	}
	cout << dp[n][m] << '\n';


	return 0;
}