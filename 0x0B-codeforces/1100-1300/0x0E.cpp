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
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	int l = 0, r = 0;
	int sum = 0;
	int res = n + 1;
	while(r < n) {
		sum += a[r];
		if(sum > s) {
			res = min(res, n = (r - l));
		}
		while(sum > s) {
			sum -= a[l++];
		}
		r++;
	}
	cout << ((res == n + 1) ? 0 : res) << '\n';
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