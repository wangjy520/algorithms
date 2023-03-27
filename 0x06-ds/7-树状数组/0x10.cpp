/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e4 + 10;

struct Fenwick {
	vector<long long> c;
	Fenwick(int n) : c(n + 1) {}
	int lowbit(int x) {
		return x & (-x);
	}
	void add(int i, int v, int n) {
		for(;i <= n;i += lowbit(i))
			c[i] += v;
	}
	long long sum(int i) {
		int res = 0;
		for(;i;i -= lowbit(i)) 
			res += c[i];
		return res;
	}
	long long sum(int i, int j) {
		return sum(j) - sum(i - 1);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v(n + 1), x(n + 1);
	for(int i = 1;i <= n;i++) {
		cin >> v[i] >> x[i];
	}
	vector<int> id(n + 1);
	iota(id.begin(), id.end(), 0);
	sort(id.begin(), id.end(), [&](int i, int j) {return x[i] < x[j];});
	long long res = 0;
	Fenwick w1(maxn), w2(maxn);
	for(int i = 1;i <= n;i++) {
		int vv = v[id[i]], xx = x[id[i]];
		long long s = w1.sum(1, vv);
		long long cnt = w2.sum(1, vv);
		res += (cnt * xx - s) * vv;
		w1.add(vv, xx, maxn);
		w2.add(vv, 1, maxn);
	}
	Fenwick w3(maxn), w4(maxn);
	for(int i = n;i > 0;i--) {
		int vv = v[id[i]], xx = x[id[i]];
		long long s = w3.sum(1, vv - 1);
		long long cnt = w4.sum(1, vv - 1);
		res += (s - cnt * xx) * vv;
		w3.add(vv, xx, maxn);
		w4.add(vv, 1, maxn);
	}
	cout << res << '\n';

	return 0;
}