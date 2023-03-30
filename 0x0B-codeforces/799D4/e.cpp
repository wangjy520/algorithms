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


void solve() {
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	vector<int> pre(n + 1, 0);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		pre[i + 1] = pre[i] + a[i];
	}
	unordered_map<int, int> m;
	m[0] = 0;
	int res = 1e9;
	for(int i = 1;i <= n;i++) {
		int c = pre[i] - s;
		if(m.find(c) != m.end()) {
			res = min(res, n - i + m[c]);
			
		}
		if(m.find(pre[i]) == m.end()) {
			m[pre[i]] = i;
		}
	}
	cout << (res == (int) 1e9 ? -1 : res) << '\n';
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