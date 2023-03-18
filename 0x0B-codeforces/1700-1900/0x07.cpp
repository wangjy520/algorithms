/* 
** Created by Wangjy.
** https://codeforces.com/problemset/problem/1359/C
** 1700
** 数学
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
	int h, c, t;
	cin >> h >> c >> t;
	if(t * 2 == (h + c)) {
		cout << 2 << '\n';
		return ;
	}
	else if (t * 2 > (h + c)) {
		// one more hot water
		int l = 0, r = 1e5;
		while(l < r) {
			int mid = (l + r + 1) >> 1;
			long long sum = mid * c + (mid + 1) * h;
			if(sum >= t * (mid + mid + 1)) {
				l = mid;
			}
			else {
				r = mid - 1;
			}
		}
		cout << l + l + 1 << '\n';
	}
	else {
		cout << 2 << '\n';
	}
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