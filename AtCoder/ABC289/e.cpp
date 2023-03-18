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
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> c(n + 1);
	for(int i = 1;i <= n;i++) {
		cin >> c[i];
	}
	vector<vector<int>> edges(n + 1, vector<int>());
	for(int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
	queue<tuple<int, int, int>> q;
	q.emplace(0, 1, n);
	while(!q.empty()) {
		auto [d, x, y] = q.front();
		q.pop();

		if(dp[x][y] != -1) 
			continue;
		dp[x][y] = d;
		for(auto& a : edges[x]) {
			for(auto& b : edges[y]) {
				if(c[a] != c[b]) {
					q.emplace(d + 1, a, b);
				}
			}
		}
	}

	cout << dp[n][1] << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	

	return 0;
}