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
const int maxn = 1e5 + 10;
int n;

struct Fenwick
{
	vector<int> c;
	Fenwick(int n) : c(n + 1, 0) {}
	int lowbit(int x) {
		return x & (-x);
	}

	void add(int i, int v, int len) {
		for(;i <= len;i += lowbit(i))
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
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vector<int> a(n);
	Fenwick w1(maxn), w2(maxn);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		w2.add(a[i], 1, maxn);
	}	
	long long res = 0;
	for(int i = 0;i < n;i++) {
		w2.add(a[i], -1, maxn);
		int ls = w1.sum(a[i] - 1), rs = w2.sum(a[i] + 1, (int) 1e5);
 		res += (long long) ls * rs;
		w1.add(a[i], 1, maxn);
	}
	cout << res << '\n';

	return 0;
}