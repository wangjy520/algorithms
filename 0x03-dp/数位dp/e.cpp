// 
// Created by Wangjy.
// https://www.spoj.com/problems/CPCRC1C/
// Accepted
// 简单的数位dp
// 本地测试跑不通，按照这种输入方式的话
// 
#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

LL compute(int x) {
	string s = to_string(x);
	int m = s.size();
	vector<vector<int>> dp(m, vector<int>(100, -1));

	function<LL(int, int, bool, bool)> f = [&](int i, int sum, bool is_limit, bool is_num) -> LL {
		if(i >= m) {
			return is_num ? sum : 0;
		}
		if(!is_limit && is_num && dp[i][sum] != -1) {
			return dp[i][sum];
		}
		LL res = 0;
		if(!is_num) {
			res += f(i + 1, sum, false, false);
		}
		for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 9);++d) {
			res += f(i + 1, sum + d, (is_limit && d == s[i] - '0'), true);
		}
		if(!is_limit && is_num)
			dp[i][sum] = res;
		return res;
	};

	return f(0, 0, true, false);
}

void solve(int a, int b) {
	cout << compute(b) - compute(a - 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	while(a != -1 && b != -1) {
		solve(a, b);
		cin >> a >> b;
	}

	return 0;
}