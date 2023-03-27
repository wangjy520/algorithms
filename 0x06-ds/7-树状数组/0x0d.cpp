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

struct Fenwick {
	vector<int> c;
	Fenwick(int n) : c(n + 1) {}
	int lowbit(int x) {
		return x & (-x);
	}
	void add(int i, int v, int n) {
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
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	vector<vector<int>> nums(q, vector<int>(2));
	for(int i = 0;i < q;i++) {
		cin >> nums[i][0] >> nums[i][1];
	}
	vector<int> id(q);
	iota(id.begin(), id.end(), 0);
	sort(id.begin(), id.end(), [&](int i, int j) {return nums[i][1] < nums[j][1];});
	Fenwick w(n + 1);
	vector<int> res(q);
	unordered_map<int, int> m;
	for(int i = 1, j = 0;i <= n;i++) {
		if(m.find(a[i]) != m.end()) {
			w.add(m[a[i]], -1, n);
		}
		m[a[i]] = i;
		w.add(i, 1, n);
		while(j < q && nums[id[j]][1] == i) {
			int l = nums[id[j]][0], r = nums[id[j]][1];
			res[id[j]] = w.sum(l, r);
			j++;
		}
	}
	for(int i = 0;i < q;i++) {
		cout << res[i] << '\n';
	}


	return 0;
}