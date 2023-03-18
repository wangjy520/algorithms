// 
// Created by Wangjy.
// https://vjudge.net/problem/LightOJ-1068
// Accepted
// 
#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

const int maxn = 82;

int compute(int k, int x) {
	if(x == 0)
		return 0;
	string s = to_string(x);
	int m = s.size();
	vector<vector<vector<int>>> dp(m, vector<vector<int>>(maxn, vector<int>(maxn, -1)));

	function<int(int, int, int, bool, bool)> f = [&](int i, int r, int num, bool is_limit, bool is_num) -> int {
		if(i >= m) {
			if(r == 0 && num == 0 && is_num)
				return 1;
			else 
				return 0;
		}
		if(!is_limit && is_num && dp[i][r][num] != -1)
			return dp[i][r][num];
		int res = 0;
		if(!is_num) {
			res += f(i + 1, r, num, false, false);
		}
		for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 9);++d) {
			res += f(i + 1, (r + d) % k, (num * 10 + d) % k, (is_limit && d == s[i] - '0'), true);
		}
		if(!is_limit && is_num)
			dp[i][r][num] = res;
		return res;
	};

	return f(0, 0, 0, true, false);
}

void solve(int t) {
	int a, b, k;
	cin >> a >> b >> k;
	// 此处必须要判断 k 的取值， 否则dp的第三维可能会超出范围
	if(k >= 82) {
		cout << "Case " << t << ": " << 0 << '\n';
	}
	else 
		cout << "Case " << t << ": " << compute(k, b) - compute(k, a - 1) << '\n';
}

int main() {
	int t;
	cin >> t;
	int n = t;
	while(t--) {
		solve(n - t);
	}

	return 0;
}