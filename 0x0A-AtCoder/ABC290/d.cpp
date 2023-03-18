/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
	int n, d, k;
	cin >> n >> d >> k;
	if(k == 1) {
		cout << 0 << '\n';
		return ;
	}
	int cnt = 1;
	vector<int> next(n, 0), pre(n, 0);
	vector<bool> fs(n, false);
	fs[0] = true;
	for(int i = 1;i < n;i++) {
		next[i - 1] = i;
		pre[i] = i - 1;
	}
	next[n - 1] = 1;
	pre[0] = n - 1;
	int a = 0, b = 0;
	while(cnt < k) {
		b = (a + d) % n;
		if(!fs[b]) {
			fs[b] = true;
		}
		else {
			b = next[b];
			fs[b] = true;
		}
		int p = pre[b];
		pre[p] = next[b];
		a = b;
		cnt++;
	}
	cout << b << '\n';
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