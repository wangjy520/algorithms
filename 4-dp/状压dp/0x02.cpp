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
	vector<vector<double>> nums(n, vector<double>(2));
	for(int i = 0;i < n;i++) {
		cin >> nums[i][0] >> nums[i][1];
	}

	vector<vector<double>> d(n, vector<double>(n, 0.0));
	for(int i = 0;i < n;i++) {
		for(int j = i + 1;j < n;j++) {
			double dis = sqrt(pow(nums[i][0] - nums[j][0], 2) + pow(nums[i][1] - nums[j][1], 2));
			d[i][j] = dis;
			d[j][i] = dis;
		}
	}
	double res = 1e9;
	for(int s = 0;s < n;s++) {
		vector<vector<double>> dp(1 << n, vector<double>(n, (double) 1e9 + 7));
		dp[1 << s][s] = sqrt(pow(nums[s][0], 2) + pow(nums[s][1], 2));
		for(int i = (1 << s);i < (1 << n);i++) {
			for(int j = 0;j < n;j++) {
				if(!(i & (1 << j)))
					continue;
				for(int k = 0;k < n;k++) {
					if((i ^ (1 << j)) & (1 << k))
						dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + d[k][j]);
				}
			}
		}
		for(int i = 0;i < n;i++) {
			res = min(res, dp[(1 << n) - 1][i]);
		}
		
	}
	printf("%.2f", res);


	return 0;
}