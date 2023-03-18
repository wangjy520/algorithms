// 
// Created by Wangjy.
// 
#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

const int maxn = 20;


// k 某个数字
// cnt k的出现次数
LL compute(vector<int>& nums, LL x) {
	string s = to_string(x);
	int m = s.size();

	vector<LL> dp(m, -1);
	vector<int> cnt(10, 0);
	function<LL(int, bool, bool)> f = [&](int i, bool is_limit, bool is_num) -> LL {
		if(i >= m) {
			bool ok = false;
			for(int i = 0;i < 10;i++) {
				if(nums[i] == cnt[i]) {
					ok = true;
					break;
				}
			}
			return ok && is_num;
		}
		if(!is_limit && is_num && dp[i] != -1)
			return dp[i];
		LL res = 0;
		if(!is_num) {
			res += f(i + 1,  false, false);
		}
		for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 9);++d) {
			cnt[d]++;
			res += f(i + 1, (is_limit &&d == s[i] - '0'), true);
			cnt[d]--;
		}
		if(!is_limit && is_num)
			dp[i] = res;
		return res;
	};
	
	return f(0, true, false);
}

void solve() {
	LL a, b;
	cin >> a >> b;
	vector<int> nums(10);
	for(int i = 0;i < 10;i++) {
		cin >> nums[i];
	}
	LL ex = 0;
	
	cout << b - a + 1 - compute(nums, b) + compute(nums, a - 1) << '\n';

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