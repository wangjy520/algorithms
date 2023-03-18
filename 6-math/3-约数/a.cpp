// 
// Created by Wangjy.
// https://www.luogu.com.cn/problem/P5436
// Accepted
// 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

void solve() {
	LL n;
	cin >> n;
	if(n == 1) {
		cout << 1 << '\n';
		return;
	}
	cout << (n - 1) * n << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}	


	return 0;
}