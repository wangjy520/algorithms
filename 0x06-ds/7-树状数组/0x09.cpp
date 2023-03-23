/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<long long> c(maxn, 0), d(maxn, 0);
int n;

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

long long sum(int i, int j) {
	return sum(j) - sum(i - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	cin >> n >> m;
	vector<int> a(n + 1, 0);
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		add(i, a[i]);
		add(i + 1, -a[i]);
	}
	for(int i = 0;i < m;i++) {
		int op, a, b;
		cin >> op >> a >> b;
		if(op == 1) {
			long long x;
			cin >> x;
			add(a, x);
			add(b + 1, -x);
		}
		else {
			cout << sum(a, b) << '\n';
		}
	}

	return 0;
}