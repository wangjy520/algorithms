/* 
** Created by Wangjy.
** https://codeforces.com/contest/1525/problem/D
** 动态规划
** 不知道为什么这么想
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int inf = 1e5 + 10;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n), chairs, people;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		if(a[i]) {
			people.push_back(i);
		}
		else {
			chairs.push_back(i);
		}
	}
	int c = chairs.size(), p = people.size();
	if(p == 0) {
		cout << 0 << '\n';
		return 0;
	}
	
	// 前i把椅子坐j个人
	vector<vector<long long>> dp(c + 1, vector<long long>(p + 1, 1e18));
	dp[0][0] = 0;
	for(int i = 1;i <= c;i++) {
		dp[i][0] = 0;
		for(int j = 1;j <= min(p, i);j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + abs(chairs[i - 1] - people[j - 1]));
		}
		
	}
	cout << dp[c][p] << '\n';


	


	return 0;
}