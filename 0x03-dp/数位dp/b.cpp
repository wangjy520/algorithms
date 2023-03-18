// 
// Created by Wangjy.
// https://codeforces.com/contest/628/problem/D
// 压根不会
// 
#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

const int mod = 1e9 + 7;


int solve(int k, int x, string s) {
	int m = s.size();
	vector<vector<int>> dp(m, vector<int>(k, -1));

	function<int(int, int, bool, bool)> f = [&](int i, int r, bool is_limit, bool is_num) -> int {
		if(i >= m) {
			return (is_num && r == 0) ? 1 : 0;
		}
		if(!is_limit && is_num && dp[i][r] != -1)
			return dp[i][r];
		int res = 0;
		if(!is_num) {
			res = (res + f(i + 1, r, false, false)) % mod;
		}
		for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 9);++d) {
			if(d == x && (i & 1) == 0)
				continue;
			res = (res + f(i + 1, (r * 10 + d) % k, (is_limit && d == s[i] - '0'), true)) % mod;
		}
		if(!is_limit && is_num)
			dp[i][r] = res;
		return res;
	};

	return f(0, 0, true, false);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k, x;
	cin >> k >> x;
	string a, b;
	cin >> a >> b;

	cout << solve(k, x, b) - solve(k, x, a) << '\n';

	return 0;
}