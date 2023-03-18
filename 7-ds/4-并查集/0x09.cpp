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


vector<int> get_primes(int n) {
	vector<int> prime;
	int cnt = 0;
	vector<int> p(n + 1);
	iota(p.begin(), p.end(), 0);
	for(int i = 2;i <= n;i++) {
		if(p[i] == i) {
			prime.push_back(i);
			cnt++;
		}
		for(int j = 0;j < cnt;j++) {
			if(prime[j] > i || prime[j] > n / i)
				break;
			p[i * prime[j]] = prime[j];
		}
	}
	return prime;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, p;
	cin >> a >> b >> p;
	DSU dsu(b + 1);

	vector<int> prime = get_primes(b);
	int index = lower_bound(prime.begin(), prime.end(), p) - prime.begin();
	for(int j = index;j < prime.size();j++) {
		// cout << prime[j] << "\n";
		for(int i = ((a + prime[j] - 1) / prime[j]);i <= (b / prime[j] - 1);i++) {
			dsu.merge(i * prime[j], (i + 1) * prime[j]);
		}
	}
	unordered_set<int> s;
	for(int i = a;i <= b;i++) {
		s.insert(dsu.find(i));
	}
	cout << s.size() << '\n';


	return 0;
}