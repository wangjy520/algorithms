/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

long long solve(long long n) {
	string s = to_string(n);
	int m = s.size();
	long long res = 0;
	for(int k = 1;k <= 162;k++) {
		vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(k + 1, vector<long long>(k, -1)));

		function<long long(int, int, int, bool, bool)> f = [&](int i, int c, int r, bool is_num, bool is_limit) -> long long {
			if(i >= m) {
				if(is_num && c == k && r == 0)
					return 1;
				else 
					return 0;
			}
			if(c > k || c + (m - i) * 9 < k)
				return 0;
			if(is_num && !is_limit && dp[i][c][r] != -1)
				return dp[i][c][r];
			long long ans = 0;
			if(!is_num)
				ans = f(i + 1, c, r, false, false);
			for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 9);d++) {
				ans += f(i + 1, c + d, ((long long) pow(10, m - i - 1) * d + r) % k, true, (is_limit && d == s[i] - '0'));
			}
			if(is_num && !is_limit)
				dp[i][c][r] = ans;
			return ans;
		};

		res += f(0, 0, 0, false, true);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b;
	cin >> a >> b;
	cout << solve(b) - solve(a - 1) << '\n';

	return 0;
}