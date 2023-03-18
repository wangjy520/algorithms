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
	vector<pii> nums(n);
	for(int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		nums[i] = make_pair(a, b);
	}
	sort(nums.begin(), nums.end(), [&](pii& a, pii& b) {return a.second < b.second;});
	vector<int> dp(n, 0);
	dp[0] = nums[0].second - nums[0].first + 1;
	for(int i = 1;i < n;i++) {
		int l = -1, r = i - 1;
		while(l < r) {
			int mid = (l + r + 1) >> 1;
			if(nums[mid].second < nums[i].first) {
				l = mid;
			}
			else {
				r = mid - 1;
			}
		}
		dp[i] = dp[i - 1];
		if(l != -1) {
			dp[i] = max(dp[i], dp[l] + nums[i].second - nums[i].first + 1);
		}
		else {
			dp[i] = max(dp[i], nums[i].second - nums[i].first + 1);
		}
	}
	
	cout << dp[n - 1] << '\n';


	return 0;
}