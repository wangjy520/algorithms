/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

struct Fenwick {
	vector<int> c;
	Fenwick(int n) : c(n, 0) {}
	int lowbit(int x) {return x & (-x);}
	void add(int i, int v, int n) {
		for(;i <= n;i += lowbit(i)) {
			c[i] ^= v;
		}
	}

	int sum(int i) {
		int ans = 0;
		for(;i > 0;i -= lowbit(i))
			ans ^= c[i];
		return ans;
	}

	int sum(int i, int j) {
		return sum(j) ^ sum(i - 1);
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	Fenwick f1(maxn), f2(maxn);
	vector<int> a(n + 1, 0);
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		if(i % 2 == 1) {
			f1.add(i, a[i], n);
		}
		else {
			f2.add(i, a[i], n);
		}
	}
	for(int i = 0;i < m;i++) {
		int op, l, r;
		cin >> op >> l >> r;
		if(op == 1) {
			int c = r ^ a[l];
			a[l] = r;
			if(l % 2 == 1)
				f1.add(l, c, n);
			else 
				f2.add(l, c, n);
		}
		else {
			int len = r - l + 1;
			if(len % 2 == 0) {
				cout << 0 << '\n';
			}
			else {
				if(l % 2 == 1) {
					cout << f1.sum(l, r) << '\n';
				}
				else {
					cout << f2.sum(l, r) << '\n';
				}
			}
		}
	}

	return 0;
}