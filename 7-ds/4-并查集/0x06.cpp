/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct DSU {
	vector<int> p, r;
	DSU(int n) : p(n), r(n, 0) {iota(p.begin(), p.end(), 0);}
	int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
	bool same(int x, int y) {return find(x) == find(y);}
	void merge(int x, int y) {
		x = find(x);
		y = find(y);
		if(r[x] < r[y]) {
			p[x] = y;
		}
		else 
			p[y] = x;
		if(x != y && r[x] == r[y])
			r[x]++;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, p;
	cin >> n >> m >> p;
	DSU dsu(n + 1);
	for(int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		dsu.merge(a, b);
	}
	for(int i = 0;i < p;i++) {
		int a, b;
		cin >> a >> b;
		cout << (dsu.same(a, b) ? "Yes" : "No") << '\n';
	}

	return 0;
}