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

vector<int> func(int n) {
	vector<int> res;
	for(int i = 0;i < (1 << n);i++) {
		if(!(i & (i << 1)))
			res.push_back(i);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;
	cin >> m >> n;
	vector<vector<int>> a(m, vector<int>(n));
	for(int i = 0;i < m;i++) {
		for(int j = 0;j < n;j++) {
			cin >> a[i][j];
		}
	}
	vector<int> s = func(n);
	int len = s.size();
	vector<vector<int>> dp(m + 1, vector<int>(len, 0));
	dp[0][0] = 1;

	for(int i = 1;i <= m;i++) {
		for(int j = 0;j < len;j++) {
			int mask = s[j];
			bool ok = true;
			for(int k = 0;k < n;k++) {
				if(a[i - 1][k] == 0 && (mask & (1 << k))) {
					ok = false;
					break;
				}
			}
			if(!ok)
				continue;
			for(int k = 0;k < len;k++) {
				if(!(s[k] & mask)) {
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
				}
			}
		}
	}
	int res = 0;
	for(int i = 0;i < len;i++) {
		res = (res + dp[m][i]) % mod;
	}
	cout << res << '\n';

	return 0;
}