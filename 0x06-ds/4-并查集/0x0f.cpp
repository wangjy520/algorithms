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
			p[x] = y;
		else
			p[y] = x;
		if(x != y && r[x] == r[y])
			r[x]++;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, W;
	cin >> n >> m >> W;
	DSU dsu(n + 1);
	vector<int> v(n + 1), w(n + 1);
	for(int i = 1;i <= n;i++) {
		cin >> w[i] >> v[i];
	}
	for(int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		dsu.merge(a, b);
	}
	unordered_map<int, int> m1, m2;
	for(int i = 1;i <= n;i++) {
		int r = dsu.find(i);
		m1[r] += w[i];
		m2[r] += v[i];
	}
	int len = m1.size();
	v.resize(len);
	w.resize(len);
	int cnt = 0;
	for(auto& p : m1) {
		w[cnt] = p.second;
		v[cnt] = m2[p.first];
		cnt++;
	}
	vector<int> dp(W + 1, 0);
	for(int i = 0;i < len;i++) {
		for(int j = W;j >= 0;j--) {
			if(j - w[i] >= 0) {
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
	}
	cout << dp[W] << '\n';

	return 0;
}