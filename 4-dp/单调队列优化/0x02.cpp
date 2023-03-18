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

// dp[i] = min(dp[j] + nums[i]), i - m <= j < i

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> nums(n);
	int res = 0;
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
		res += nums[i];
	}
	if(m == 1) {
		cout << res << '\n';
		return 0;
	}

	vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	deque<int> q;
	q.push_back(0);
	for(int i = 1;i < n;i++) {
		while(!q.empty() && q.front() < i - m) {
			q.pop_front();
		}
		dp[i] = dp[q.front()] + nums[i];
		while(!q.empty() && dp[q.back()] > dp[i])
			q.pop_back();
		q.push_back(i);
	}

	for(int i = n - 1;i >= n - m;i--) {
		res = min(res, dp[i]);
	}

	cout << res << '\n';


	return 0;
}