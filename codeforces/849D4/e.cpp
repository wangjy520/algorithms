/* 
** Created by Wangjy.
** 贪心
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve() {
	int n;
	cin >> n;
	int neg = 0;
	LL res = 0;
	vector<int> nums(n);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
		if(nums[i] < 0) {
			neg++;
			nums[i] = -nums[i];
		}
		res += nums[i];
	}
	if(neg % 2 == 1) {
		int mn = *min_element(nums.begin(), nums.end());
		res -= 2 * mn;
	}
	cout << res << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	


	return 0;
}