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
	int n, k, d, w;
	cin >> n >> k >> d >> w;
	vector<int> a(n);
	for(int i = 0; i < n;i++) {
		cin >> a[i];
	}
	int res = 0;
	int i = 0, j = 0;
	int valid = a[i] + w + d;
	int cnt = 0;
	while(i < n) {
		while(j < n && a[j] <= valid && cnt < k) {
			j++;
			cnt++;
		}
		if(j < n) {
			res++;
			valid = a[j] + w + d;
			i = j;
			cnt = 0;
		}
		else {
			break;
		}
	}
	res++;
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