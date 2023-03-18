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
const int mod = 1e9 + 7;
/*
	dp[i] = max(dp[j - 1] + sum(nums[j + 1] ~ nums[i])), i - k <= j < i
	dp[i] = max(dp[j] + pre[i + 1] - pre[j + 1]), i - k <= j < i
	
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<LL> nums(n);
	vector<LL> pre(n + 1, 0);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
		pre[i + 1] = pre[i] + nums[i];
	}
	deque<LL> q;
	vector<LL> dp(n);
	dp[0] = nums[0];
	q.push_back(0);
	for(int i = 1;i < n;i++) {
		while(!q.empty() && q.front() < i - k) 
			q.pop_front();
		dp[i] = ((q.front() > 0) ? dp[q.front() - 1] - pre[q.front() + 1] : 0) + pre[i + 1];
		while(!q.empty() && (dp[q.back()] - pre[q.back() + 1]) < (dp[i] - pre[i + 1]))
			q.pop_back();
		q.push_back(i);
	}
	
	cout << dp[n - 1] << '\n';






	return 0;
}