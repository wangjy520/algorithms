/* 
** Created by Wangjy.
** https://codeforces.com/problemset/problem/466/C
** https://codeforces.com/blog/entry/13758
** 前缀和或者双指针，其实主要考察的是巧妙的思路
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const LL inf = 1e18;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	LL s = 0LL;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		s += a[i];
	}
	if(s % 3 != 0) {
		cout << 0 << '\n';
		return 0;
	}
	LL num = s / 3;
	vector<int> cnt(n + 1, 0), sums(n + 1, 0);
	LL c = 0;
	for(int i = n - 1;i >= 0;i--) {
		c += a[i];
		if(c == num) {
			cnt[i] = 1;
		}
		sums[i] = sums[i + 1] + cnt[i];
	}
	LL res = 0;
	c = 0;
	for(int i = 0;i < n;i++) {
		c += a[i];
		if(c == num) {
			if(i + 2 < n) {
				res += sums[i + 2];
			}
		}
	}
	cout << res << '\n';


	return 0;
}