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
	vector<string> a(8);
	for(int i = 0;i < 8;i++) {
		cin >> a[i];
	}
	for(int i = 1;i < 7;i++) {
		for(int j = 1;j < 7;j++) {
			if(a[i][j] == '#' &&a[i + 1][j + 1] == '#' && a[i - 1][j - 1] == '#' && a[i - 1][j + 1] == '#' && a[i + 1][j - 1] == '#') {
				cout << i + 1 << ' ' << j + 1 << '\n';
				return ;
			}
		}
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