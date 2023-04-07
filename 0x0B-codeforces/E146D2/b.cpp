/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

long long solve(long long n) {
	long long l = 0, r = 1e5;
	while(l < r) {
		long long mid = (l + r + 1) >> 1;
		long long s = (mid + 2) * (mid + 1) / 2;
		if(s <= n) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	return l;
}

long long solve1(long long n) {
	long long l = 0, r = 1e5;
	while(l < r) {
		long long mid = (l + r) >> 1;
		long long s = (mid + 1) * mid / 2;
		if(s >= n) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	return l;
}

void solve() {
	int a, b;
	cin >> a >> b;
	long long mx = solve(max(a, b));
	long long x = solve1(max(a, b));
	long long y = solve1(min(a, b));
	// cout <<solve1(5) << '\n';
	cout << mx << " " << x << " " << y << '\n';
	// cout << mx + solve1(max(a, b)) + solve1(min(a, b)) << '\n';
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