// 
// Created by Wangjy.
// 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int maxn = 310;
int n, m;
vector<vector<int>> edges(maxn, vector<int>());
int s[maxn];
int children[maxn];
int size[maxn];
int maxChild = 0;
int dp[maxn][maxn][maxn];

void dfs2(int i, int par) {
	dp[i][0][1] = s[i];
	for(int j = 1;j <= children[i];j++) {
		int child = edges[i][j - 1];
		dfs2(child, i);
		for(int k = 0;k <= m + 1;k++) {
			for(int t = 0;t <= size[child];t++) {
				dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - t] + dp[child][children[child]][t]);
			}
		}
	}
}


void dfs1(int i, int par) {
	children[i] = 0;
	size[i] = 1;
	for(auto child : edges[i]) {
		if(child == par)
			continue;
		dfs1(child, i);
		children[i]++;
		size[i] += size[child];
	}

	// maxChild = max(maxChild, children[i]);
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 0;i < n;i++) {
		int pre, cost;
		cin >> pre >> cost;
		edges[pre].push_back(i + 1);
		s[i + 1] = cost;
	}
	dfs1(0, -1);
	dfs2(0, -1);
	int res = 0;
	for(int i = 0;i < maxn;i++) {
		res = max(res, dp[0][i][m + 1]);
	}
	cout << res << '\n';


	return 0;
}