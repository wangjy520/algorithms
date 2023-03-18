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
const int maxn = 2e4 + 10;
vector<vector<int>> edges(maxn, vector<int>());
vector<int> dfn(maxn, 0);
vector<int> low(maxn, 0);
vector<int> cut(maxn, false);
int cnt = 0;
int n, m;
int root;

void tarjan(int i, int par) {
	cnt++;
	dfn[i] = cnt;
	low[i] = cnt;
	int flag = 0;
	for(auto& child : edges[i]) {
		if(child == par)
			continue;
		if(dfn[child] == 0) {
			tarjan(child, i);
			low[i] = min(low[i], low[child]);
			if(dfn[i] <= low[child]) {
				flag++;
				if(i != root || flag > 1) {
					cut[i] = true;
				}
			}
		}
		else {
			low[i] = min(low[i], dfn[child]);
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for(int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for(int i = 1;i <= n;i++) {
		if(dfn[i] == 0) {
			root == i;
			tarjan(i, -1);
		}
	}
	// vector<int> res;
	// for(int i = 1;i <= n;i++) {
	// 	if(cut[i])
	// 		res.push_back(i);
	// }
	// cout << res.size() << '\n';
	// for(auto& ans : res) {
	// 	cout << ans << ' ';
	// }

	for(int i = 1;i <= n;i++) {
		cout << cut[i] << " ";
	}

	return 0;
}