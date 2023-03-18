/* 
** Created by Wangjy.
** https://www.luogu.com.cn/problem/P1396
** Accepted
** 二分答案 + SPFA算法
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int n, m, s, t;
const int maxn = 1e4 + 10;
vector<vector<pii>> edges(maxn, vector<pii>());

bool check(int mid) {
	vector<int> d(maxn, maxn);
	d[s] = 0;
	queue<int> q;
	q.push(s);
	unordered_set<int> sset;
	sset.insert(s); 
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		sset.erase(node);
		for(auto child : edges[node]) {
			int next = child.first;
			int w = child.second;
			if(d[next] > max(w, d[node])) {
				d[next] = max(w, d[node]);
				if(sset.find(next) == sset.end()) {
					sset.insert(next);
					q.push(next);
				}
			}
		}
	}
	return mid >= d[t];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	
	cin >> n >> m >> s >> t;	
	for(int i = 0;i < m;i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edges[a].push_back({b, w});
		edges[b].push_back({a, w});
	}

	int l = 0, r = maxn;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l << '\n';

	return 0;
}