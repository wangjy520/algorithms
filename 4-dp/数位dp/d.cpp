// 
// Created by Wangjy.
// https://codeforces.com/contest/919/problem/B
// 二分答案 + 数位dp
// 按照题目给出的范围，直接暴力也能过
// Accepted
// 
#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

int solve(LL num) {
	string s = to_string(num);
	int m = s.size();
	vector<vector<int>> dp(m, vector<int>(180, -1));

	function<LL(int, int, bool, bool)> f = [&](int i, int cnt, bool is_limit, bool is_num) -> LL {
		if(i >= m) {
			return is_num && cnt == 10;
		}
		if(!is_limit && is_num && dp[i][cnt] != -1) {
			return dp[i][cnt];
		}
		LL res = 0;
		if(!is_num) {
			res += f(i + 1, cnt, false, false);
		}
		for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 9);++d) {
			res += f(i + 1, cnt + d, (is_limit && d == s[i] - '0'), true);
		}
		if(!is_limit && is_num)
			dp[i][cnt] = res;
		return res;
	};

	return f(0, 0, true, false);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;
	LL l = 1, r = INT_MAX;
	while(l < r) {
		LL mid = (l + r) >> 1;
		if(solve(mid) >= k) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l << '\n';

	return 0;
}