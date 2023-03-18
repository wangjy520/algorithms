/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int maxn = 2e5 + 10;
int n;
vector<vector<pii>> edges(maxn, vector<pii>());
int mx = maxn;
vector<int> res;
vector<int> dp(maxn, 0);

void dfs1(int i, int par) {
	for(auto& p : edges[i]) {
		int child = p.first, fs = p.second;
		if(child == par)
			continue;
		dfs1(child, i);
		dp[i] += dp[child];
		if(!fs) {
			dp[i]++;
		}
	}
}

void dfs2(int i, int par) {
	for(auto& p : edges[i]) {
		int child = p.first, fs = p.second;
		if(child == par)
			continue;
		if(fs) {
			dp[child] = dp[i] + 1;
		}
		else {
			dp[child] = dp[i] - 1;
		}
		dfs2(child, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for(int i = 0;i < n - 1;i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back({b, 1});
		edges[b].push_back({a, 0});
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for(int i = 1;i <= n;i++) {
		if(dp[i] < mx) {
			res.resize(1);
			res[0] = i;
			mx = dp[i];
		}
		else if(mx == dp[i]) {
			res.push_back(i);
		}
	}
	cout << mx << '\n';
	for(auto& ans : res) {
		cout << ans << ' ';
	}


	return 0;
}