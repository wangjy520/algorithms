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

const int mod = 998244353;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> d(n + 1, 0);
	vector<vector<int>> edges(n + 1, vector<int>());
	for(int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		d[b]++;
		edges[a].push_back(b);
	}
	queue<int> q;
	for(int i = 1;i <= n;i++) {
		if(d[i] == 0) {
			q.push(i);
		}
	}
	int cnt = 1;
	vector<int> res(n + 1);
	if(q.size() > 1) {
		cout << "No" << '\n';
		return 0;
	}
	
	while(!q.empty()) {
		int c = q.front();
		res[c] = cnt++;
		q.pop();
		for(auto& child : edges[c]) {
			d[child]--;
			if(d[child] == 0) {
				q.push(child);
			}
		}
		if(q.size() > 1) {
			cout << "No" << '\n';
			return 0;
		}
	}
	cout << "Yes" << '\n';
	for(int i = 1;i <= n;i++) {
		cout << res[i] << " ";
	}


	return 0;
}