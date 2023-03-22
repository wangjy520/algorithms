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

int solve(string s) {
	int m = s.size();
	int dp[m][11][11][2];
	memset(dp, -1, sizeof(dp));

	function<int(int, int, int, int, bool, bool)> f = [&](int i, int p1, int p2, int mask, bool is_num, bool is_limit) -> int {
		if(i >= m) {
			return is_num && mask;
		}
		if(is_num && !is_limit && dp[i][p1][p2][mask] != -1)
			return dp[i][p1][p2][mask];
		int ans = 0;
		if(!is_num) {
			ans = f(i + 1, p1, p2, mask, false, false);
		}
		for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 9);d++) {
			ans = (ans + f(i + 1, p2, d, mask || d == p2 || d == p1, true, is_limit && d == s[i] - '0')) % mod;
		}
		if(is_num && !is_limit)
			dp[i][p1][p2][mask] = ans;
		return ans;
	};
	return f(0, 10, 10, 0, false, true);
}	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string l, r;
	cin >> l >> r;
	bool fs = false;
	for(int i = 1;i < l.size();i++) {
		if(l[i] == l[i - 1] || i >= 2 && l[i] == l[i - 2]) {
			fs = true;
			break;
		}
	}
	cout << (solve(r) - solve(l) + mod + fs) % mod << '\n';

	return 0;
}