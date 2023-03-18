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

struct DSU
{
	vector<int> p, r, s;
	DSU(int n) : p(n), r(n, 0), s(n, 1) {iota(p.begin(), p.end(), 0);}
	int find(int x) {
		return x == p[x] ? x : (p[x] = find(p[x]));
	}
	bool same(int x, int y) {return find(x) == find(y);}
	void merge(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y)
			return ;
		if(r[x] < r[y]) {
			p[x] = y;
			s[y] += s[x];
		}
		else {
			s[x] += s[y];
			p[y] = x;
		}
		if(x != y && r[x] == r[y])
			r[x]++;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, p, q;
	cin >> n >> m >> p >> q;
	DSU d1(n + 1), d2(m + 1);
	for(int i = 0;i < p;i++) {
		int a, b;
		cin >> a >> b;
		d1.merge(a, b);
	}
	for(int i = 0;i < q;i++) {
		int a, b;
		cin >> a >> b;
		d2.merge(-a, -b);
	}

	
	cout << min(d1.s[d1.find(1)], d2.s[d2.find(1)]) << '\n';

	return 0;
}