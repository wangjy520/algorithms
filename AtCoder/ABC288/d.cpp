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
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
	}
	vector<LL> pre(n + 1, 0L);
	for(int i = 1;i <= n;i++) {
		pre[i] = pre[i - 1] + nums[i - 1];
	}
	int q;
	cin >> q;
	for(int i = 0;i < q;i++) {
		int l, r;
		cin >> l >> r;
		cout << ((pre[r] - pre[l - 1]) % k == 0 ? "Yes" : "No") << '\n';
	}

	return 0;
}