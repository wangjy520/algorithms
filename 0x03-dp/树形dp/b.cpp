// 
// Created by Wangjy.
// 
// https://www.luogu.com.cn/problem/P2016
// Accepted
// 本题中不需要考虑以哪个节点为根节点是最优解，都不会影响答案
// 而且在属性dp中，不需要考虑父节点，只考虑子节点就够了


#include<bits/stdc++.h>
typedef long long LL;
using namespace std;



void dfs(int i, vector<vector<int>>& edges, vector<vector<int>>& dp, int par) {
	int s = 0, t = 0;
	for(auto child : edges[i]) {
		if(par == child)
			continue;
		dfs(child, edges, dp, i);
		dp[i][0] += dp[child][1];
		dp[i][1] += min(dp[child][0], dp[child][1]);
	}
	dp[i][1] += 1;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> edges(n, vector<int>());
	for(int i = 0;i < n;i++) {
		int a, k;
		cin >> a >> k;
		for(int j = 0;j < k;j++) {
			int b;
			cin >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
	}
	vector<vector<int>> dp(n, vector<int>(2, 0));
	dfs(0, edges, dp, -1);
	cout << min(dp[0][0], dp[0][1]) << '\n';


	return 0;
}