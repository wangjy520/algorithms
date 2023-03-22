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
const int mod = 1e9 + 7;

int solve(LL n) {
	string s = to_string(n);
	int m = s.size();

	vector<vector<int>> dp(m, vector<int>(m * 9 + 1, -1));

	function<int(int, int, bool, bool)> f = [&](int i, int c, bool is_num, bool is_limit) -> int {
		if(i >= m) {
			return is_num ? c : 0;
		}
		if(is_num && !is_limit && dp[i][c] != -1) {
			return dp[i][c];
		}
		int res = 0;
		if(!is_num) {
			res = f(i + 1, c, false, false);
		}
		for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 9);d++) {
			res = (res + f(i + 1, c + d, true, (is_limit && s[i] - '0' == d))) % mod;
		}
		if(is_num && !is_limit)
			dp[i][c] = res;
		return res;
	};
	return f(0, 0, false, true);
}

void solve() {
	LL a, b;
	cin >> a >> b;
	cout << (solve(b) - solve(a - 1) + mod) % mod << '\n';
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