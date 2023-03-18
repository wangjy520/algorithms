/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int maxn = 1e6 + 10;
int n;
int c[maxn];
int lowbit(int x) {
	return x & (-x);
}

void add(int i, int v) {
	for(;i <= n;i += lowbit(i)) {
		c[i] += v;
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
	cin.tie(0);

	cin >> n;
	vector<int> nums(n);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
	}
	int m;
	cin >> m;
	vector<pii> a(m);
	for(int i = 0;i < n;i++) {
		int x, y;
		cin >> x >> y;
		a[i] = make_pair(x, y);
	}
	sort(a.begin(), a.end(), [&](pii& o, pii& p) {return o.second < p.second;});
	


	return 0;
}