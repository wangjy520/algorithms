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
	int n;
	cin >> n;
	vector<int> a(n);
	unordered_map<int, int> m;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	int res = m.size();
	int s = 0;
	for(auto& p : m) {
		if(p.second % 2 == 0) {
			s++;
		}
	}
	if(s % 2 == 1)
		res--;
	cout << res << '\n';
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