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
	long long c, d;
	cin >> n >> c >> d;
	vector<long long> a(n);
	unordered_map<long long, int> m;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	sort(a.begin(), a.end());
	long long res = 1e18;
	for(int i = n - 1;i >= 0;i--) {
		long long dd = 0, cc = c * (n - i - 1);
		cc += c * (i + 1 - m.size());
		dd += d * (a[i] - m.size());
		res = min(res, cc + dd);
		int cnt = m[a[i]];
		if(cnt == 1)
			m.erase(a[i]);
		else 
			m[a[i]]--;
	}
	res = min(res, c * n + d);
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