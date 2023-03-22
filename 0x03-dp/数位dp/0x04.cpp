/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

long long solve(long long n) {
	string s = to_string(n);
	int m = s.size();

	vector<vector<long long>> dp(m, vector<long long>(4, -1));

	function<long long(int, int, bool, bool)> f = [&](int i, int c, bool is_num, bool is_limit) -> long long {
		if(i >= m) {
			return is_num;
		}
		if(is_num && !is_limit && dp[i][c] != -1)
			return dp[i][c];
		long long ans = 0;
		if(!is_num)
			ans = f(i + 1, c, false, false);
		for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 9);d++) {
			if(d == 0 || c < 3)
				ans += f(i + 1, c + (d > 0), true, (is_limit && d == s[i] - '0'));
		}
		if(is_num && !is_limit)
			dp[i][c] = ans;
		return ans;
	};
	return f(0, 0, false, true);
	
}

void solve() {
	long long a, b;
	cin >> a >> b;
	cout << solve(b) - solve(a - 1) << '\n';
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