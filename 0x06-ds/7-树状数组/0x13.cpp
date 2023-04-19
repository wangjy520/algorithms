/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

struct Fenwick {
	vector<long long> c, d;
	Fenwick(int n) : c(n + 1, 0), d(n + 1, 0) {}
	int lowbit(int x) {
		return x & (-x);
	}
	void add(int i, int n, int x) {
		for(int j = i;j <= n;j += lowbit(j)) {
			c[j] += x;
			d[j] += (long long) (i - 1) * x;
		}
	}
	long long sum(int i) {
		long long res = 0;
		for(int j = i;j > 0;j -= lowbit(j)) {
			res += (long long) i * c[j] - d[j];
		}
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	Fenwick w(n);
	for(int i = 1;i <= n;i++) {
		int a;
		cin >> a;
		w.add(i, n, a);
		if(i + 1 <= n)
			w.add(i + 1, n, -a);
	}	
	for(int i = 0;i < q;i++) {
		int op;
		cin >> op;
		if(op == 1)  {
			int l, r, x;
			cin >> l >> r >> x;
			w.add(l, n, x);
			if(r + 1 <= n)
				w.add(r + 1, n, -x);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << w.sum(r) - w.sum(l - 1) << '\n';
		}
	}
	return 0;
}