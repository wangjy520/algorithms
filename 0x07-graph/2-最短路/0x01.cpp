/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>

using namespace std;
constexpr int maxn = 110;
int n, m;
vector<vector<pair<int, int>>> edges(maxn, vector<pair<int, int>>());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	vector<vector<int>> d(n + 1, vector<int>(n + 1, (int) 2e9));
	for(int i = 0;i < m;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		d[u][v] = min(w, d[u][v]);
		d[v][u] = min(w, d[v][u]);
	}
	vector<pair<int, int>> g;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(d[i][j] != 2e9) {
				edges[i].push_back({j, d[i][j]});
				if(i < j) {
					g.push_back({i, j});
				}
			}
		}
	}
	int res = 2e9;
	for(auto& p : g) {
		int s = p.first, t = p.second;
		vector<int> dis(n + 1, -1);
		vector<bool> v(n + 1, false);
		auto cmp = [&](int i, int j) -> bool {
			return dis[i] > dis[j];
		};
		priority_queue<int, vector<int>, decltype(cmp)> h(cmp);
		dis[s] = 0;
		h.push(s);
		while(!h.empty()) {
			int i = h.top();
			h.pop();
			if(i == t) {
				break;
			}
			if(v[i])
				continue;
			v[i] = true;
			for(auto& p : edges[i]) {
				int child = p.first, w = p.second;
				if(i == s && child == t)
					continue;
				if(dis[child] == -1 || dis[child] > dis[i] + w) {
					dis[child] = dis[i] + w;
					h.push(child);
				}
			}
		}
		if(dis[t] != -1) {
			res = min(res, dis[t] + d[s][t]);
		}
	}
	if(res == 2e9)
		cout << "No solution.\n";
	else 
		cout << res << '\n';

	return 0;
}