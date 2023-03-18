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
	LL a, b, n, m;
	cin >> a >> b >> n >> m;
	LL res = 0;
	if((a * m) <= (m + 1) * b) {
		cout << (n / (m + 1) * (a * m) + ((n % (m + 1)) == 0 ? 0 : min(min(a * m, (n % (m + 1)) * a), (n % (m + 1)) * b))) << '\n';
	}
	else {
		cout << n * b << '\n';
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