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
const int inf = 1e5;

// void dfs(int i, int j, vector<vector<int>>& dp) {

// }

void solve() {
	int a, b;
	cin >> a >> b;
	a = abs(a);
	b = abs(b);
	int m = min(a, b), n = max(a, b);
	if(abs(a - b) <= 1) {
		cout << m + n << '\n';
	}
	else {
		cout << (m * 2 + (n - m) * 2 - 1) << '\n';
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