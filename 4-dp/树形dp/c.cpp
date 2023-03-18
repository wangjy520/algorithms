// 
// Created by Wangjy.
// https://www.luogu.com.cn/problem/P3174
// Accepted
// 
#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

const int maxn = 3e5 + 10;
vector<vector<int>> edges(maxn, vector<int>());

vector<int> f(maxn);
vector<int> g(maxn);
int ans = 0;

void dfs(int i, int par) {
	int m = 0;
	int res = 1;
	int s = edges[i].size() - (par != 0);
	for(auto& child : edges[i]) {
		if(child == par)
			continue;
		dfs(child, i);
		// 此处必须还要加上父节点才行
		res = max(res, m + f[child] + 1 + max(0, s - 2) + (par != 0 ? 1 : 0));
		m = max(m, f[child]);
		g[i]++;
	}
	
	f[i] = m + 1 + max(0, s - 1);
	
	ans = max(ans, res);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	for(int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(n, 0);
	// for(int i = 1;i <= n;i++) {
	// 	cout << i << " : " << f[i]  << '\n';
	// }
	cout << ans << '\n';

	return 0;
}