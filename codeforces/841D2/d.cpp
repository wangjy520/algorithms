// 
// Created by Wangjy.
// 
#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

bool check(vector<vector<int>>& a, int i, int m, int n) {
	vector<vector<int>> b(m, vector<int>(n, 0));
	vector<vector<int>> p(m + 1, vector<int>(n + 1, 0));
	for(int j = 0;j < m;j++) {
		for(int k = 0;k < n;k++) {
			if(a[j][k] >= i) {
				b[j][k] = 1;
			}
		}
	}

	for(int j = 1;j <= m;j++) {
		for(int k = 1;k <= n;k++) {
			p[j][k] = p[j - 1][k] + p[j][k - 1] - p[j - 1][k - 1] + b[j - 1][k - 1];
		}
	}
	for(int j = i;j <= m;j++) {
		for(int k = i;k <= n;k++) {
			int row = j - i, col = k - i;
			int sum = p[j][k] - p[row][k] - p[j][col] + p[row][col];
			if(sum == i * i) {
				return true;
			}
		}
	}
	return false;
}

void solve() {
	int n, m;
	cin >> m >> n;
	vector<vector<int>> a(m, vector<int>(n));
	for(int i = 0;i < m;i++) {
		for(int j = 0;j < n;j++) {
			cin >> a[i][j];
		}
	}
	
	int s = min(m,n);
	int l = 0, r = s;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(a, mid, m, n)) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	bool ok = check(a, l, m, n);
	cout << (ok ? l : l - 1) << '\n';
}

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
	return 0;
}