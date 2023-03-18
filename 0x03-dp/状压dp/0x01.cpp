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

const int mod = 1e8;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;
	cin >> m >> n;
	vector<vector<int>> nums(m, vector<int>(n));
	vector<int> land(m);
	for(int i = 0;i < m;i++) {
		int mask = 0;
		for(int j = 0;j < n;j++) {
			cin >> nums[i][j];
			if(nums[i][j] == 1) {
				mask |= (1 << j);
			}
		}
		land[i] = mask;
	}

	vector<int> s;
	for(int i = 0;i < (1 << n);i++) {
		if((i & (i << 1)) == 0 && (i & (i >> 1)) == 0) {
			s.push_back(i);
		}
	}

	vector<vector<int>> dp(m + 1, vector<int>(1 << n, 0));
	dp[0][0] = 1;
	for(int i = 1;i <= m;i++) {
		for(auto mask : s) {
			if((mask | land[i - 1]) > land[i - 1])
				continue;
			for(auto pre : s) {
				if((pre & mask) == 0) {
					dp[i][mask] = (dp[i][mask] + dp[i - 1][pre]) % mod;
				}
			}
		}
	}
	int res = 0;
	for(auto mask : s) {
		res = (res + dp[m][mask]) % mod;
	}
	cout << res << '\n';



	return 0;
}