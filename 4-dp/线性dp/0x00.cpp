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
int res = INT_MAX;

void solve(vector<int>& nums, int s) {
	int n = nums.size();
	vector<int> dp(n + 1, 0);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
	}

	vector<int> dp1(n, 1);
	// dp1[0] = 
	for(int i = 1;i < n;i++) {
		for(int j = i - 1;j >= 0;j--) {
			if(nums[i] > nums[j])
				dp1[i] = max(dp1[i], dp1[j] + 1);
		}
	}
	vector<int> dp2(n, 1);
	for(int i = n - 2;i >= 0;i--) {
		for(int j = i + 1;j < n;j++) {
			if(nums[i] > nums[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}
	int res = 0;
	for(int i = 0;i < n;i++) {
		res = max(res, dp1[i] + dp2[i]);
	}
	cout << n - res + 1 << '\n';


	return 0;
}