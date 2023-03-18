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

const int maxn = 2e5 + 10;
LL c[maxn];

int lowbit(int x) {
	return x & (-x);
}

void add(int i, int v, int n) {
	for(;i <= n;i += lowbit(i)) {
		c[i] += v;
	}
}

int sum(int i) {
	int res = 0;
	for(;i > 0;i -= lowbit(i)) {
		res += c[i];
	}
	return res;
}

int sum(int i, int j) {
	return sum(j) - sum(i - 1);
}

int compute(int x, int cnt) {
	int i = 0;
	while(i < cnt && x / 10 > 0) {
		int y = x;
		int sum = 0;
		while(y > 0) {
			sum += y % 10;
			y /= 10;
		}
		x = sum;
		i++;
	}
	return x;
}

void solve() {
	for(int i = 0;i < maxn;i++) {
		c[i] = 0;
	}
	int n, q;
	cin >> n >> q;
	vector<int> nums(n);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
	}
	for(int i = 0;i < q;i++) {
		int k;
		cin >> k;
		if(k == 1) {
			int l, r;
			cin >> l >> r;
			add(l, 1, n);
			add(r + 1, -1, n);
		}
		else {
			int x;
			cin >> x;
			int cnt = sum(x);
			cout << compute(nums[x - 1], cnt) << '\n';
		}
	}
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