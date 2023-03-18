/* 
** Created by Wangjy.
** https://codeforces.com/problemset/problem/161/D
** 1800
** 树形dp
** https://codeforces.com/blog/entry/4097
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int maxn = 5e4 + 10;
const int maxk = 510;
vector<vector<int>> edges(maxn, vector<int>());
int n, k;
vector<vector<int>> dp(maxn, vector<int>(maxk, 0));
long long res = 0;

void dfs(int i, int par) {
	dp[i][0] = 1;
	for(auto& child : edges[i]) {
		if(child == par)
			continue;
		dfs(child, i);
		dp[i][1]++;
		for(int j = 2;j <= k;j++) {
			dp[i][j] += dp[child][j - 1];
		}
	}
	long long s = 0;
	for(auto& child : edges[i]) {
		if(child == par)
			continue;
		for(int j = 1;j < k;j++) {
			s += 1LL * dp[child][j - 1] * (dp[i][k - j] - dp[child][k - j - 1]);
		}
	}
	res += s / 2;
	res += dp[i][k];
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for(int i = 0;i < n - 1;i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(1, 0);

	cout << res << '\n';
	return 0;
}