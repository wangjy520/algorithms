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

int gcd(int m, int n) {
	return n == 0 ? m : gcd(n, m % n);
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for(int i = 0;i < n;i++) {
		for(int j = i + 1;j < n;j++) {
			if(gcd(a[i], a[j]) <= 2) {
				cout << "Yes" << '\n';
				return ;
			}
		}
	}
	cout << "NO" << '\n';
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