/* 
** Created by Wangjy.
** https://codeforces.com/problemset/problem/1365/D
** 1700
** dfs
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int i, int j, vector<vector<bool>>& v, vector<string>& a) {
	if(a[i][j] == '#')
		return ;
	v[i][j] = true;
	int n = v.size(), m = v[0].size();
	for(auto& d : dirs) {
		int row = i + d[0], col = j + d[1];
		if(row >= 0 && row < n && col >= 0 && col < m && !v[row][col] && a[row][col] != '#') {
			v[row][col] = true;
			if(a[row][col] == '.' || a[row][col] == 'G')
				dfs(row, col, v, a);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	vector<vector<bool>> v(n, vector<bool>(m, false));
	dfs(n - 1, m - 1, v, a);
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			if(a[i][j] == 'B' && v[i][j]) {
				for(auto& d : dirs) {
					int row = i + d[0], col = j + d[1];
					if(row >= 0 && row < n && col >= 0 && col < m && a[row][col] == '.') {
						a[row][col] = '#';
					}
				}
			}
		}
	}
	vector<vector<bool>> v1(n, vector<bool>(m, false));
	dfs(n - 1, m - 1, v1, a);
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			if(a[i][j] == 'G' && !v1[i][j] || a[i][j] == 'B' && v1[i][j]) {
				cout << "No" << '\n';
				return ;
			}
		}
	}
	cout << "Yes" << '\n';

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