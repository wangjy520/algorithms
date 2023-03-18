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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			cin >> a[i][j];
		}
	}

	vector<LL> c(1 << n, 0LL);
	for(int i = 0;i < (1 << n);i++) {
		vector<int> v;
		for(int j = 0;j < n;j++) {
			if(i & (1 << j)) {
				v.push_back(j);
			}
		}
		for(int j = 0;j < v.size();j++) {
			for(int k = j + 1;k < v.size();k++) {
				c[i] += a[v[j]][v[k]];
			}
		}
	}
	vector<LL> dp(1 << n, 0LL);
	for(int i = 0;i < (1 << n);i++) {
		int mask = i;
		int subset = mask;
		while(subset > 0) {
			dp[mask] = max(dp[mask], dp[mask ^ subset] + c[subset]);
			subset = (subset - 1) & mask;
		}
	}
	cout << dp[(1 << n) - 1] << '\n';
 
	return 0;
}