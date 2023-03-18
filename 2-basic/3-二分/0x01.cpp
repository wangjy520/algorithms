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
int n, m;
vector<int> a(maxn);

bool check(int mid) {
	int s = 0;
	int cnt = 0;
	for(int i = 0;i < n;i++) {
		if(a[i] > mid) {
			return false;
		}
		if(s + a[i] <= mid) {
			s += a[i];
		}
		else {
			cnt++;
			s = a[i];
		}
	}
	return cnt + 1 <= m;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	int l = 0, r = 1e9 + 10;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l << '\n';

	return 0;
}