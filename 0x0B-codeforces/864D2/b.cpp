/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			cin >> a[i][j];
		}
	}
	int s = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			s += a[i][j] != a[n + 1 - i][n + 1 - j];
		}
	}
	s /= 2;
	if(k >= s && (n % 2 == 1 || k % 2 == s % 2)) {
		cout << "Yes" << '\n';
	}
	else {
		cout << "No" << '\n';
	}
	// cout << s << '\n';
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