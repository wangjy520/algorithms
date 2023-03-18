// 
// Created by Wangjy.
// WA
// 题意没理解好
// https://www.spoj.com/problems/RAONE/
// 
#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

int compute(int x) {
	if(x <= 0)
		return 0;
	string s = to_string(x);
	int m = s.size();
	vector<vector<vector<int>>> dp(m, vector<vector<int>>(37, vector<int>(37, -1)));
	 function<int(int, int, int, bool, bool)> f = [&](int i, int odd, int even, bool is_limit, bool is_num) -> int {
	 	if(i >= m) {
	 		return is_num && (abs(odd - even) == 1);
	 	}
	 	if(!is_limit && is_num && dp[i][odd][even] != -1) {
	 		return dp[i][odd][even];
	 	}
	 	int res = 0;
	 	if(!is_num) {
	 		res += f(i + 1, odd, even, false, false);
	 	}
	 	for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 9);++d) {
	 		res += f(i + 1, odd + ((i & 1) == 0 ? d : 0), even + ((i & 1) == 1 ? d : 0), (is_limit && d == s[i] - '0'), true);

	 	}
	 	if(!is_limit && is_num)
	 		dp[i][odd][even] = res;
	 	return res;
	 };

	 return f(0, 0, 0, true, false);
}


void solve() {
	int a, b;
	cin >> a >> b;
	cout << compute(b) - compute(a - 1) << '\n';
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