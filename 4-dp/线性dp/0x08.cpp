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



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<LL> d(n + 1, 1);
	for(int i = 2;i <= n;i++) {
		for(int j = 2;j < sqrt(i);j++) {
			if(i % j == 0) {
				d[i] += j;
				d[i] += i / j;
			}
		}
		if(sqrt(i) * sqrt(i) == i)
			d[i] += sqrt(i);
	}
	vector<LL> dp(n + 1, 0);
	LL res = 0;
	for(int i = 2;i <= n;i++) {
		dp[i] = d[i];
		for(int j = i - 1;j >= 0;j--) {
			dp[i] = max(dp[j] + dp[i - j], dp[i]);
		}
		res = max(res, dp[i]);
	}
	cout << res << '\n';


	return 0;
}