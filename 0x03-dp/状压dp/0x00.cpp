/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int count(LL n) {
	int res = 0;
	while(n > 0) {
		res++;
		n -= n & (-n);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> s;
	for(int i = 0;i < (1 << n);i++) {
		if(((i << 1) & i) == 0 && ((i >> 1) & i) == 0) {
			s.push_back(i);
		}
	}
	vector<vector<vector<LL>>> dp(n + 1, vector<vector<LL>>(k + 1, vector<LL>(1 << n, 0)));
	dp[0][0][0] = 1;
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j <= k;j++) {
			for(auto c : s) {
				for(auto p : s) {
					if((c & p) != 0)
						continue;
					if(((c << 1) & p) != 0)
						continue;
					if(((c >> 1) & p) != 0)
						continue;
					int cnt = count(c);
					if(j - cnt >= 0) {
						dp[i][j][c] = (dp[i][j][c] + dp[i - 1][j - cnt][p]);
					}
				}
			}
		}
	}
	LL res = 0;
	for(auto mask : s) {
		res += dp[n][k][mask];
	}
	
	cout << res << '\n';


	return 0;
}