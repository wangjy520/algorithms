// 
// Created by Wangjy.
// TLE
// 
#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

const int mod = 1000000007;

LL compute(string s) {
	int m = s.size();
	vector<vector<vector<vector<LL>>>> dp(m, vector<vector<vector<LL>>>(52, vector<vector<LL>>(52, vector<LL>(52, -1))));

	function<LL(int, int, int ,int, bool, bool)> f = [&](int i, int c1, int c2, int c3, bool is_limit, bool is_num) -> LL {
		if(i >= m) {
			return is_num && (c1 == c2) && (c2 == c3) && (c1 != 0);
		}
		if(!is_limit && is_num && dp[i][c1][c2][c3] != -1) {
			return dp[i][c1][c2][c3];
		}
		LL res = 0;
		if(!is_num) {
			res = (res +  f(i + 1, c1, c2, c3, false, false)) % mod;
		}
		for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 9);++d) {
			if(d == 3) {
				res =  (res + f(i + 1, c1 + 1, c2, c3, (is_limit && d == s[i] - '0'), true)) % mod;
			}
			else if(d == 6) {
				res =  (res + f(i + 1, c1, c2 + 1, c3, (is_limit && d == s[i] - '0'), true)) % mod;
			}
			else if(d == 9) {
				res =  (res + f(i + 1, c1, c2, c3 + 1, (is_limit && d == s[i] - '0'), true)) % mod;
			}
			else {
				res =  (res + f(i + 1, c1, c2, c3, (is_limit && d == s[i] - '0'), true)) % mod;
			}
		}
		if(!is_limit && is_num) {
			dp[i][c1][c2][c3] = res;
		}
		return res;
	};

	return f(0, 0, 0, 0, true, false);
}

void solve() {
	string a,b;
	cin >> a >> b;
	int c1 = 0,c2 = 0, c3 = 0;
	for(auto ch : a) {
		if(ch == '3') {
			c1++;
		}
		else if(ch == '6')
			c2++;
		else if(ch == '9')
			c3++;
	}
	int sub = (c1 == c2 && c2 == c3 && c1 != 0);
	cout << (compute(b) - compute(a) + sub + mod) % mod << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}