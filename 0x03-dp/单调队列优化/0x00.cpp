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



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<LL> nums(n);
	for(int i = 0;i < n;i++)  {
		cin >> nums[i];
	}
	vector<LL> pre(n + 1, 0L);
	for(int i = 1;i <= n;i++) {
		pre[i] = pre[i - 1] + nums[i - 1];
	}
	vector<vector<LL>> dp(n, vector<LL>(2, 0));
	deque<int> q;
	dp[0][0] = 0;
	dp[0][1] = nums[0];
	q.push_back(0);
	for(int i = 1;i < n;i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		if(i < k) {
			dp[i][1] = pre[i + 1];
		}
		else {
			while(!q.empty() && q.front() < i - k)
				q.pop_front();
			dp[i][1] = pre[i + 1] + dp[q.front()][0] - pre[q.front() + 1];
		}
		
		while(!q.empty() && (dp[q.back()][0] - pre[q.back() + 1]) <= (dp[i][0] - pre[i + 1]))
			q.pop_back();
		q.push_back(i);
	}
	
	cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';

	return 0;
}