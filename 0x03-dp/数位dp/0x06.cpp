/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

long long solve(long long n) {
	string s = to_string(n);
	int m = s.size();
	long long dp[m][11][11][2][2][2];
	memset(dp, -1, sizeof(dp));

	function<long long(int, int, int, int, int, int, bool, bool)> f = [&](int i, int p1, int p2, int mask, int fs4, int fs8, bool is_num, bool is_limit) -> long long {
		if(i >= m) {
			if(is_num && mask && !(fs4 && fs8))
				return 1;
			else 
				return 0;
		}
		if(is_num && !is_limit && dp[i][p1][p2][mask][fs4][fs8] != -1)
			return dp[i][p1][p2][mask][fs4][fs8];
		long long res = 0;
		if(!is_num)
			res = f(i + 1, p1, p2, mask, fs4, fs8, false, false);
		for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 9);d++) {
			if(p1 == p2 && p2 == d) {
				res += f(i + 1, p2, d, true, fs4 || (d == 4), fs8 || (d == 8), true, is_limit && d == s[i] - '0');
			}
			else {
				res += f(i + 1, p2, d, mask, fs4 || (d == 4), fs8 || (d == 8), true, is_limit && d == s[i] - '0');
			}
		}
		if(is_num && !is_limit)
			dp[i][p1][p2][mask][fs4][fs8] = res;
		return res;
	};
	return f(0, 10, 10, 0, 0, 0, false, true);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b;
	cin >> a >> b;
	cout << solve(b) - solve(a - 1) << '\n';

	return 0;
}