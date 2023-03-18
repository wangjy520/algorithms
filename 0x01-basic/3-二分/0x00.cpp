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
int L, n, m;
vector<int> a(maxn, 0);

bool check(int mid) {
	int cnt = 0;
	int pre = 0;
	for(int i = 1;i <= n + 1;i++) {
		if(a[i] - pre < mid) {
			cnt++;
		}
		else {
			pre = a[i];
		}
	}
	return cnt <= m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> L >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.begin() + n + 1);
	a[n + 1] = L;
	int l = 0, r = 2e9;
	while(l < r) {
		int mid = ((long long) l + r + 1) >> 1;
		if(check(mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << l << '\n';

	return 0;
}