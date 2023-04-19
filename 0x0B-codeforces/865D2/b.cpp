/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<bool> used(2 * n + 1, false);
	int i = 2 * n, j = 1;
	int cnt = 0;
	while(cnt < n) {
		if(cnt < n) {
			cout << i-- << ' ';
			cnt++;
		}
		if(cnt < n) {
			cout << j++ << ' ';
			cnt++;
		}
	}
	cout << '\n';
	cnt = 0;
	while(cnt < n) {
		if(cnt < n) {
			cout << j++ << ' ';
			cnt++;
		}
		if(cnt < n) {
			cout << i-- << ' ';
			cnt++;
		}
	}
	cout << '\n';
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