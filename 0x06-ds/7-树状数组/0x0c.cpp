/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>

using namespace std;
const int maxn = 5e5 + 10;
int n;
vector<int> c(maxn, 0);

int lowbit(int x) {
	return x & (-x);
}

void add(int i, int x) {
	for(;i <= n;i += lowbit(i))
		c[i] += x;
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

	unordered_map<int, int> m;
	int cnt = 1;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	vector<int> id(n);
	iota(id.begin(), id.end(), 0);
	sort(id.begin(), id.end(), [&](int i, int j) {return a[i] < a[j];});
	for(int i = 0;i < n;i++) {
		int k = a[id[i]];
		if(m.find(k) == m.end()) {
			m[k] = cnt++;
		}
	}

	long long res = 0;
	for(int i = 1;i <= n;i++) {
		res += sum(m[a[i - 1]] + 1, cnt - 1);
		add(m[a[i - 1]], 1);
	}
	cout << res << '\n';

	return 0;
}