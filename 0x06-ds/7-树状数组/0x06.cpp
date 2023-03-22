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
const int maxn = 1e7 + 10;
int n, m;
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

	cin >> n >> m;
	for(int i = 0;i < m;i++) {
		int op;
		cin >> op;
		if(op) {
			int a;
			cin >> a;
			cout << sum(a) << '\n';
		}
		else {
			int a, b;
			cin >> a >> b;
			add(a, 1);
			add(b + 1, -1);
		}
	}

	return 0;
}