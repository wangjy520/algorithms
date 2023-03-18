// 
// Created by Wangjy.
// https://www.luogu.com.cn/problem/P1122
// 简单树形dp
// Accepted
// 
#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
int ans = INT_MIN;

void dfs(vector<vector<int>>& edges, vector<int>& a, vector<int>& dp, int i, int par) {
	int res = 0;
	for(auto child : edges[i]) {
		if(child == par)
			continue;
		dfs(edges, a, dp, child, i);

		res += (dp[child] > 0 ? dp[child] : 0);
	}
	dp[i] = res > 0 ? res + a[i] : a[i];
	ans = max(ans, dp[i]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> edges(n + 1, vector<int>());
	vector<int> a(n + 1);
	vector<int> dp(n + 1, INT_MIN);
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for(int i = 0;i < n - 1;i++) {
		int s, t;
		cin >> s >> t;
		edges[s].push_back(t);
		edges[t].push_back(s);
	}
	dfs(edges, a, dp, 1, 0);
	cout << ans << '\n';



	return 0;
}