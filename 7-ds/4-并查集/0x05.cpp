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
const int maxn = 1e6 + 10;

struct DSU
{
	vector<int> p, r;
	DSU(int n) : p(n), r(n, 0) {iota(p.begin(), p.end(), 0);}
	int find(int x) {
		return x == p[x] ? x : (p[x] = find(p[x]));
	}
	bool same(int x, int y) {return find(x) == find(y);}
	void merge(int x, int y) {
		x = find(x);
		y = find(y);
		if(r[x] < r[y])
			p[x] = p[y];
		else
			p[y] = p[x];
		if(x != y && r[x] == r[y])
			r[x]++;
	}
};

void solve() {
	int n;
	cin >> n;
	DSU dsu(maxn);
	vector<pii> nums;
	int cnt = 1;
	unordered_map<int, int> m;
	for(int i = 0;i < n;i++) {
		int a, b, e;
		cin >> a >> b >> e;
		if(m.find(a) == m.end()) {
			m[a] = cnt++;
		}
		a = m[a];
		if(m.find(b) == m.end()) {
			m[b] = cnt++;
		}
		b = m[b];
		if(e == 0) {
			nums.push_back({a, b});
		}
		else {
			dsu.merge(a, b);
		}
	} 
	for(auto& p : nums) {
		if(dsu.same(p.first, p.second)) {
			cout << "NO" << '\n';
			return ;
		}
	}
	cout << "YES" << '\n';
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