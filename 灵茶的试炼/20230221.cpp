/* 
** Created by Wangjy.
** https://codeforces.com/problemset/problem/5/C
** 线性dp，现在看来是转移的方式比较特别
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	vector<int> dp(n + 1, 0);
	for(int i = 2;i <= n;i++) {
		if(s[i - 1] == '(') 
			continue;
		if(s[i - 2] == '(') {
			dp[i] = dp[i - 2] + 2;
		}
		else {
			int len = dp[i - 1];
			if(s[i - len - 2] == '(') {
				dp[i] = dp[i - len - 2] + 2 + len;
			}
		}
	}
	int mx = -1;
	int res = 0;
	for(int i = 1;i <= n;i++) {
		if(dp[i] == 0)
			continue;
		if(mx == dp[i]) {
			res++;
		}
		else if(mx < dp[i]) {
			mx = dp[i];
			res = 1;
		}
	}
	if(mx != -1)
		cout << mx << " " << res << '\n';
	else
		cout << 0 << " " << 1 << '\n';

	return 0;
}