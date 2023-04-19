/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

struct Fenwick {
	vector<long long> c;
	Fenwick(int n) : c(n + 1, 0) {}
	int lowbit(int x) {
		return x & (-x);
	}

	void add(int i, int v, int n) {
		for(;i <= n;i += lowbit(i)) {
			c[i] += v;
		}
	}

	long long sum(int i) {
		long long ans = 0;
		for(;i > 0;i -= lowbit(i)) {
			ans += c[i];
		}
		return ans;
	}

	long long sum(int i, int j) {
		return sum(j) - sum(i - 1);
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	Fenwick w(n);
	for(int i = 0;i < n;i++) {
		int a;
		cin >> a;
		w.add(i + 1, a, n);
		if(i + 1 < n)
			w.add(i + 2, -a, n);
	}
	for(int i = 0;i < q;i++) {
		int op;
		cin >> op;
		if(op == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			w.add(l, x, n);
			if(r < n)
				w.add(r + 1, -x, n);
		}
		else {
			int m;
			cin >> m;
			cout << w.sum(m) << '\n';
		}
	}

	return 0;
}