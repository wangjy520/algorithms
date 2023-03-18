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

const int maxn = 1e5 + 10;
const int maxk = 22;
vector<vector<int>> edges(maxn, vector<int>());
vector<int> c(maxn);
vector<vector<int>> dp(maxn, vector<int>(maxk, 0));
vector<vector<int>> g(maxn, vector<int>(maxk, 0));
int n, k;
vector<int> res(maxn, 0);

void dfs1(int i, int par) {
	dp[i][0] = c[i];
	for(auto& child : edges[i]) {
		if(child == par) {
			continue;
		}
		dfs1(child, i);
		for(int j = 1;j <= k;j++) {
			dp[i][j] += dp[child][j - 1];
		}
	}
}

void dfs2(int i, int par) {
	g[i][0] = c[i];
	for(int j = 1;j <= k;j++) {
		g[i][j] = g[par][j - 1];
	}
	for(int j = 0;j <= k;j++) {
		res[i] += (g[i][j] + dp[i][j]);
	}
	res[i] -= c[i];
	for(auto& child : edges[i]) {
		if(child == par)
			continue;
		dfs2(child, i);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	
	cin >> n >> k;
	
	
	for(int i = 0;i < n - 1;i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}	
	for(int i = 1;i <= n;i++) {
		cin >> c[i];
	}

	dfs1(1, 0);
	dfs2(1, 0);
	for(int i = 1;i <= n;i++) {
		cout << res[i] << '\n';
	}


	return 0;
}