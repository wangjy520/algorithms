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
	int n, w, h;
	cin >> n >> w >> h;
	vector<int> a(n), b(n);
	for(int &i : a)
		cin >> i;
	for(int &i : b) {
		cin >> i;
	}
	vector<pii> ins(n);
	for(int i = 0;i < n;i++) {
		ins[i] = make_pair(b[i] + h - w - a[i], b[i] - h + w - a[i]);
	}
	int l = INT_MIN, r = INT_MAX;
	for(auto& p : ins) {
		l = max(l, p.first);
		r = min(r, p.second);
	}
	if(l <= r) {
		cout << "Yes" << '\n';
	}
	else {
		cout << "No" << '\n';
	}
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