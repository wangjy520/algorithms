// 
// Created by Wangjy.
// https://www.luogu.com.cn/problem/CF219D
// Accepted

// 
#include<bits/stdc++.h>
typedef long long LL;

using namespace std;
typedef pair<int, int> pii;

const int maxn = 2e5 + 10;
int dp[maxn];
int g[maxn];
int s[maxn];

void dfs1(int i, vector<vector<pii>>& edges, int par) {
	dp[i] = 0;
	for(auto child : edges[i]) {
		if(child.first == par)
			continue;
		dfs1(child.first, edges, i);
		dp[i] += child.second + dp[child.first];
		s[i] += s[child.first] + 1;
	}
	// dp[i];
}

void dfs2(int i, vector<vector<pii>>& edges, int par) {
	
	if(par != -1) {
		for(auto child : edges[par]) {
			if(child.first == i) {
				if(child.second == 1)
					dp[i] = dp[par] - 1;
				else 
					dp[i] = dp[par] + 1;
				break;
			}
		}
	
	}
	for(auto child : edges[i]) {
		if(par != child.first) {
			dfs2(child.first, edges,i);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<pii>> edges(n + 1, vector<pii>());
	for(int i = 0;i < n - 1;i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back({b, 0});
		edges[b].push_back({a, 1});
	}
	dfs1(1, edges, -1);
	dfs2(1, edges, -1);
	int sum = maxn;
	vector<int> res;
	for(int i = 1;i <= n;i++) {
		sum = min(sum, dp[i]);
		// cout << i << ":" << dp[i] << " " << g[i] << '\n';
	}
	for(int i = 1;i <= n;i++) {
		if(sum == dp[i]) {
			res.push_back(i);
		}
	}

	cout << sum << '\n';
	for(auto r : res)
		cout << r << " ";

	return 0;
}