/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << min((x1 != 1) + (x1 != n) + (y1 != 1) + (y1 != m), (x2 != 1) + (x2 != n) + (y2 != 1) + (y2 != m)) << '\n';
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