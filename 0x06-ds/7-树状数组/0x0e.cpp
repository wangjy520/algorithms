/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;
// constexpr int inf = (1 << 10) + 10;
struct Fenwick {
	vector<vector<int>> c;
	Fenwick(int n) : c(n + 1, vector<int>(n + 1, 0)) {}
	int lowbit(int x) {
		return x & (-x);
	}
	void add(int a, int b, int v, int n) {
		for(int i = a;i <= n;i += lowbit(i)) {
			for(int j = b;j <= n;j += lowbit(j)) {
				c[i][j] += v;
			}
		}
	}
	int sum(int a, int b) {
		int res = 0;
		for(int i = a;i;i -= lowbit(i)) {
			for(int j = b;j;j -= lowbit(j))
				res += c[i][j];
		}
		return res;
	}
	int sum(int a, int b, int x, int y) {
		return sum(x, y) - sum(a - 1, y) - sum(x, b - 1) + sum(a - 1, b - 1);
	}
};

void solve() {
	int n;
	cin >> n;
	Fenwick w(n);
	string s;
	cin >> s;
	while(s != "END") {
		if(s == "SET") {
			int x, y, v;
			cin >> x >> y >> v;
			int k = w.sum(x + 1, y + 1, x + 1, y + 1);
			w.add(x + 1, y + 1, v - k, n);
		}
		else {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			cout << w.sum(a + 1, b + 1, c + 1, d + 1) << '\n';
		}
		cin >> s;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}	

	return 0;
}