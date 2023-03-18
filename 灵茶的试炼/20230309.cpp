/* 
** Created by Wangjy.
** https://codeforces.com/contest/652/problem/D
** 很好的思路，将区间按照右端点排序（先离散化），然后使用树状数组依次统计
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int maxn = 2e5 + 10;
vector<int> c(maxn * 2, 0);
int n;
int cnt = 1;

int lowbit(int x) {
	return x & (-x);
}

void add(int i) {
	for(;i < maxn * 2;i += lowbit(i)) {
		c[i]++;
	}
}

int sum(int i) {
	int res = 0;
	for(;i > 0;i -= lowbit(i)) {
		res += c[i];
	}
	return res;
}

int sum(int i, int j) {
	return sum(j) - sum(i - 1);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vector<vector<int>> a(n, vector<int>(2));
	vector<int> b(n * 2);
	cnt = 1;
	for(int i = 0;i < n;i++) {
		int l, r;
		cin >> l >> r;
		a[i][0] = l;
		a[i][1] = r;
		b[i] = l;
		b[i + n] = r;
	}
	sort(b.begin(), b.end());
	unordered_map<int, int> m;
	
	for(int i = 0;i < b.size();i++) {
		if(m.find(b[i]) == m.end()) {
			m[b[i]] = cnt++;
		}
	}
	for(int i = 0;i < n;i++) {
		a[i][0] = m[a[i][0]];
		a[i][1] = m[a[i][1]];
	}
	vector<int> id(n);
	iota(id.begin(), id.end(), 0);
	sort(id.begin(), id.end(), [&](int i, int j) {return a[i][1] == a[j][1] ? a[i][0] > a[j][0] : a[i][1] < a[j][1];});
	vector<int> res(n);
	for(int i = 0;i < n;i++) {
		res[id[i]] = sum(a[id[i]][0], a[id[i]][1]);
		add(a[id[i]][0]);
	}
	for(int i = 0;i < n;i++) {
		cout << res[i] << '\n';
	}


	return 0;
}