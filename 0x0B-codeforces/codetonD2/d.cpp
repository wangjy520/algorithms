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

long long search(long long a, long long b, long long h) {
	long long l = 1, r = h;
	while(l < r) {
		long long mid = (l + r) >> 1;
		if((mid - 1) * (a - b) + a >= h) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	return l;
}


void solve() {
	int q;
	cin >> q;
	long long l = -1, r = -1;
	for(int i = 0;i < q;i++) {
		long long op, a, b;
		cin >> op >> a >> b;
		if(op == 1) {
			long long n;
			cin >> n;
			if(l == -1) {
				r = (n - 1) * (a - b) + a;
				if(n == 1) {
					l = 1;
				}
				else {
					l = max((n - 2) * (a - b) + a, (n - 1) * (a - b)) + 1;
				}
				cout << 1 << " ";
			}
			else {
				long long left = -1, right = -1;
				right = (n - 1) * (a - b) + a;
				if(n == 1) {
					left = 1;
				}
				else {
					left = max((n - 2) * (a - b) + a, (n - 1) * (a - b)) + 1;
				}
				if(right < l || left > r) {
					cout << 0 << ' ';
					continue;
				}
				else {
					cout << 1 << " ";
					l = max(l, left);
					r = min(r, right);
				}
			}
			// cout << '\n';
			// cout << l << " " << r << '\n';
		}
		else {
			if(l == -1) {
				cout << -1 << " ";
				continue;
			}
			else {
				long long d1 = search(a, b, l);
				long long d2 = search(a, b, r);

				if(d1 == d2) {
					cout << d1 << " ";
				}
				else {
					cout << -1 << " ";
				}
			}
			
		}
	}
	// cout << search(6, 2, 6) << ' ' << search(6, 2, 1) << '\n';
	cout << '\n';
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