// 
// Created by Wangjy..
// https://www.luogu.com.cn/problem/P3478
// Accepted
// 原来这就是传说中的换根dp或者二次扫描法
// 本题是换根dp的板子
// 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int maxn = 1e6 + 10;
vector<vector<int>> edges(maxn, vector<int>());
LL dp[maxn];
int s[maxn];

void dfs1(int i, int par) {
	dp[i] = 0;
	s[i] = 1;
	for(auto child : edges[i]) {
		if(child == par)
			continue;
		dfs1(child, i);
		s[i] += s[child];
		dp[i] += dp[child] + s[child];
	}
}

void dfs2(int i, int par, int n) {
	if(par != -1) {
		dp[i] = dp[par] + (n - s[i] * 2);
	}
	for(auto child : edges[i]) {
		if(child == par)
			continue;
		dfs2(child, i, n);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 0;i < n - 1;i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	dfs1(1, -1);
	dfs2(1, -1, n);
	int res = 0;
	LL sum = 0;
	for(int i = 1;i <= n;i++) {
		if(dp[i] > sum) {
			res = i;
			sum = dp[i];
		}
	}
	cout << res << '\n';




	return 0;
}