/* 
** Created by Wangjy.
** https://codeforces.com/problemset/problem/474/D
** 线性dp
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int mod = 1e9 + 7;

vector<int> init(int k) {
	vector<int> dp((int) 1e5 + 10, 0);
	dp[0] = 1;
	for(int i = 1;i <= (int) 1e5;i++) {
		dp[i] = dp[i - 1];
		if(i - k >= 0) {
			dp[i] = (dp[i] + dp[i - k]) % mod;
		}
	}
	vector<int> pre((int)1e5 + 10, 0);
	pre[0] = 1;
	for(int i = 1;i <= (int)1e5;i++) {
		pre[i] = (pre[i - 1] + dp[i]) % mod;
	}
	return pre;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, k;
	cin >> t >> k;
	vector<int> dp = init(k);
	while(t--) {
		int a, b;
		cin >> a >> b;
		if(a == 0)
			cout << dp[b] << '\n';
		else 
			cout << (dp[b] - dp[a - 1] + mod) % mod << '\n';
	}

	return 0;
}