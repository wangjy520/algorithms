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

void solve() {
	int n, c;
	cin >> n >> c;
	vector<int> nums(n);
	for(auto & i : nums) {
		cin >> i;
	}
	for(int i = 0;i < n;i++) {
		nums[i] += i + 1;
	}
	sort(nums.begin(), nums.end());
	int res = 0;
	int i = 0;
	while(i < n) {
		if(c >= nums[i]) {
			c -= nums[i];
			res++;
			i++;
		}
		else {
			break;
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}