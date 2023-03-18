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
	int n, x, p;
	cin >> n >> x >> p;
	vector<int> m(min(n, p) + 1, 0);
	LL s = 0;
	for(int i = 1;i <= min(n, p);i++) {
		s += i;
		m[i] = (s + x) % n;
		if(m[i] == 0) {
			cout << "Yes" <<'\n';
			return ;
		}
	}
	// if(p > n) {
	// 	for(int i = 1;i <= n;i++) {
	// 		// (a * m[n] + m[i]) % n == 0 and (a * n + i <= p)
	// 		// (a * m[n]) % n == n - m[i]?
	// 		if((n - m[i] + (p - i) / n * m[n]) % m[n] == 0) {
	// 			cout << "Yes" << '\n';
	// 			return ;
	// 		}
	// 	}	
	// }
	
	cout << "No" << '\n';
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