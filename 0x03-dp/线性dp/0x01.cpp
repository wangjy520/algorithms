/* 
** Created by Wangjy.
** AC
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
	}
	vector<int> dp1(n);
	vector<int> dp2(n);
	dp1[0] = nums[0];
	for(int i = 1;i < n;i++) {
		dp1[i] = max(nums[i] + dp1[i - 1], abs(nums[i] - nums[0]) * (i + 1));
		for(int j = i - 2;j >= 0;j--) {
			dp1[i] = max(dp1[i], dp1[j] + (i - j) * abs(nums[i] - nums[j + 1]));
		}
	}
	dp2[n - 1] = nums[n - 1];
	for(int i = n - 2;i >= 0;i--) {
		dp2[i] = max(nums[i] + dp2[i + 1], abs(nums[i] - nums[n - 1]) * (n - i));
		for(int j = i + 2;j < n;j++) {
			dp2[i] = max(dp2[i], (j - i) * abs(nums[i] - nums[j - 1]) + dp2[j]);
		}
	}
	int res = max(dp1[n - 1], dp2[0]);
	for(int i = 0;i < n - 1;i++) {
		res = max(res, dp1[i] + dp2[i + 1]);
	}
	cout << res << '\n';


	return 0;
}