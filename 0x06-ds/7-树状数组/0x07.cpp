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
int n, p;
const int maxn = 5e6 + 10;
vector<int> c(maxn, 0);

int lowbit(int x) {
	return x & (-x);
}

void add(int i, int v) {
	for(;i <= n;i += lowbit(i))
		c[i] += v;
}

int sum(int i) {
	int res = 0;
	for(;i > 0;i -= lowbit(i))
		res += c[i];
	return res;
}

int sum(int i, int j) {
	return sum(j) - sum(i - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> p;
	vector<int> d(n + 1, 0);
	for(int i = 1;i <= n;i++) {
		int a;
		cin >> a;
		d[i] += a;
		if(i + 1 <= n)
			d[i + 1] -= a;
	}	
	for(int i = 0;i < p;i++) {
		int l, r, k;
		cin >> l >> r >> k;
		// add(l, k);
		// add(r + 1, -k);
		d[l] += k;
		if(r + 1 <= n)
			d[r + 1] -= k;
	}
	int mn = INT_MAX;
	int s = 0;
	for(int i = 1;i <= n;i++) {
		s += d[i];
		mn = min(mn, s);
	}
	cout << mn << '\n';
	return 0;
}