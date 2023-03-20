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
	int s1 = 0, s2 = 0;
	for(int i = 0;i < n;i++) {
		int a;
		cin >> a;
		if(a % 2) {
			s2 += a;
		}
		else {
			s1 += a;
		}
	}
	cout << ((s1 > s2) ? "Yes" : "No") << '\n';
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