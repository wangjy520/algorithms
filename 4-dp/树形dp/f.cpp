// 
// Created by Wangjy.
// https://www.luogu.com.cn/problem/P2986
// Accepted
// 换根dp板子
// 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int n;
const int maxn = 1e5 + 10;
vector<vector<pii>> edges(maxn, vector<pii>());
LL dp[maxn];
LL nums[maxn];
LL s[maxn];

void dfs1(int i, int par) {
	s[i] = nums[i];
	for(auto child : edges[i]) {
		if(child.first == par)
			continue;
		dfs1(child.first, i);
		s[i] += s[child.first];
		dp[i] += dp[child.first] + s[child.first] * child.second;
	}
}

void dfs2(int i, int par, int distance) {
	if(par != -1) {
		dp[i] = dp[par] + (s[1] - s[i] * 2) * distance;
	}
	for(auto child : edges[i]) {
		if(child.first == par)
			continue;
		dfs2(child.first, i, child.second);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> nums[i];
	}
	for(int i = 0;i < n - 1;i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edges[a].push_back({b, w});
		edges[b].push_back({a, w});
	}

	dfs1(1, -1);
	dfs2(1, -1, -1);
	LL res = LLONG_MAX;
	for(int i = 1;i <= n;i++) {
		res = min(res, dp[i]);
	}
	cout << res << '\n';


	return 0;
}