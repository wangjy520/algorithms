/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

string convert(int num) {
	if(num == 0)
		return "0";
	string s = "";
	bool ok = false;
	for(int i = 30;i >= 0;i--) {
		if((num >> i) & 1) {
			ok = true;
			s += "1";
		}
		else if(ok) {
			s += "0";
		}
	}
	return s;
}

int solve(int n) {
	string s = convert(n);
	int m = s.size();
	vector<vector<vector<int>>> dp(m, vector<vector<int>>(m + 1, vector<int>(m + 1, -1)));

	function<int(int, int, int, bool, bool)> f = [&](int i, int c, int r, bool is_num, bool is_limit) -> int {
		if(i >= m) {
			return is_num && c >= r;
		}
		if(is_num && !is_limit && dp[i][c][r] != -1)
			return dp[i][c][r];
		int res = 0;
		if(!is_num) {
			res = f(i + 1, c, r, false, false);
		}
		for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 1);d++) {
			if(d)
				res += f(i + 1, c, r + 1, true, is_limit && (d == s[i] - '0'));
			else
				res += f(i + 1, c + 1, r, true, is_limit && (d == s[i] - '0'));
		}
		if(is_num && !is_limit)
			dp[i][c][r] = res;
		return res;
	};

	return f(0, 0, 0, false, true);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;
	cout << solve(b) - solve(a - 1) << '\n';

	return 0;
}