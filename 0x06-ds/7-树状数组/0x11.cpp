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
	}
	for(int i = 0;i < q;i++) {
		int op, x, y;
		cin >> op >> x >> y;
		if(op == 1) {
			w.add(x, y, n);
		}
		else {
			cout << w.sum(x, y) << '\n';
		}
	}

	return 0;
}