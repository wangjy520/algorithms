/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

const int mod = 998244353;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i] >> b[i];
	}
	vector<vector<int>> dp(n, vector<int>(2, 0));
	dp[0][0] = 1;
	dp[0][1] = 1;
	for(int i = 1;i < n;i++) {
		if(a[i - 1] != a[i]) {
			dp[i][0] = (dp[i][0] + dp[i - 1][0]) % mod;
		}
		if(b[i - 1] != a[i]) {
			dp[i][0] = (dp[i][0] + dp[i - 1][1]) % mod;
		}
		if(b[i] != a[i- 1]) {
			dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;
		}
		if(b[i] != b[i - 1]) {
			dp[i][1] = (dp[i][1] + dp[i - 1][1]) % mod;
		}
	}
	cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << '\n';



	return 0;
}