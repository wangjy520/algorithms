/* 
** Created by Wangjy.
** https://www.luogu.com.cn/problem/P1873
** Accpted
** 简单的二分答案
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int maxn = 1e6 + 10;
int n, m;
vector<int> nums(maxn);

bool check(int mid) {
	LL s = 0;
	for(auto num : nums) {
		s += max(0, num - mid);
	}
	return s >= m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
	}

	int l = 0, r = maxn;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	
	cout << l << '\n';

	return 0;
}