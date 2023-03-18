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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges(n + 1, vector<int>());
	for(int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
	}

	int ans = 0;

	for(int i = 1; i <= n;i++) {
		queue<int> q;
		q.push(i);
		vector<bool> v(n + 1, false);
		v[i] = true;

		while(!q.empty()) {
			int x = q.front();
			q.pop();
			for(auto& child : edges[x]) {
				if(!v[child]) {
					v[child] = true;
					ans++;
					q.push(child);
				}
			}
		}
	}

	cout << ans - m << '\n';

	return 0;
}