// 
// Created by Wangjy.
// https://www.luogu.com.cn/problem/P2052
// Accepted
// 常规树形dp
// 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int maxn = 1e6 + 10;
int n;
vector<vector<pii>> edges(maxn + 1, vector<pii>());
LL dp[maxn];
LL s[maxn];

void dfs1(int i, int par) {
	s[i] = 1;
	for(auto& child : edges[i]) {
		if(child.first == par)
			continue;
		dfs1(child.first, i);
		s[i] += s[child.first];
	}
}

void dfs2(int i, int par) {
	for(auto& child : edges[i]) {
		if(child.first == par)
			continue;
		dfs2(child.first, i);
		dp[i] += dp[child.first] + abs(n - s[child.first] - s[child.first]) * child.second;
		
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for(int i = 0;i < n - 1;i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edges[a].push_back({b, w});
		edges[b].push_back({a, w});
	}

	dfs1(1, -1);
	dfs2(1, -1);

	cout << dp[1] << '\n';


	return 0;
}