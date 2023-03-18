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

void solve() {
	int n;
	cin >> n;
	vector<int> nums(n);
	int s = 0;
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
		s += nums[i];
	}
	int res = -2;
	for(int i = 0;i < n - 1;i++) {
		if(nums[i] == -1 && nums[i + 1] == -1) {
			res = max(res, 2);
		}
		else if(nums[i] != nums[i + 1]) {
			res = max(res, 0);
		}
	}
	cout << s + res * 2 << '\n';

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