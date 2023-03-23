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
const int maxn = 2e5 + 10;
int n, m;

vector<long long> c(maxn, 0), d(maxn, 0);

int lowbit(int x) {
	return x & (-x);
}

void add(int i, long long x) {
	for(int j = i;j <= n;j += lowbit(j)) {
		c[j] += x;
		d[j] += (i - 1) * x;
	}
}

long long sum(int i) {
	long long res = 0;
	for(int j = i;j > 0;j -= lowbit(j)) {
		res += i * c[j] - d[j];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		long long a;
		cin >> a;
		add(i, a);
		add(i + 1, -a);
	}
	for(int i = 0;i < m;i++) {
		int op;
		cin >> op;
		if(op == 1) {
			int l, r;
			long long k;
			cin >> l >> r >> k;
			add(l, k);
			add(r + 1, -k);
		}
		else if(op == 2) {
			long long k;
			cin >> k;
			add(1, k);
			add(2, -k);
		}
		else if(op == 3) {
			long long k;
			cin >> k;
			add(1, -k);
			add(2, k);
		}
		else if(op == 4) {
			int l, r;
			cin >> l >> r;
			cout << sum(r) - sum(l - 1) << '\n';
		}
		else {
			cout << sum(1) << '\n';
		}
	}

	return 0;
}