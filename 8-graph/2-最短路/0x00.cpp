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
const int maxn = 1e3 + 10;
const int inf = INT_MAX;
int n, m;
vector<vector<pii>> edges(maxn, vector<pii>()), anti(maxn, vector<pii>());

vector<int> func(vector<vector<pii>>& g) {
	vector<int> d(n + 1, inf);
	d[1] = 0;
	queue<int> q;
	q.push(1);
	unordered_set<int> s;
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		s.erase(node);
		for(auto& p : g[node]) {
			int child = p.first, w = p.second;
			if(d[child] > d[node] + w) {
				d[child] = d[node] + w;
				if(s.find(child) == s.end()) {
					s.insert(child);
					q.push(child);
				}
			}
		}
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for(int i = 0;i < m;i++) {
		int a ,b, w;
		cin >> a >> b >> w;
		edges[a].push_back({b, w});
		anti[b].push_back({a, w});
	}
	vector<int> d1 = func(edges);
	vector<int> d2 = func(anti);
	int res = 0;
	for(int i = 2;i <= n;i++) {
		res += d1[i] + d2[i];
	}
	cout << res << '\n';

	return 0;
}