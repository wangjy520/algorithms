/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

void solve() {
	long long n, k;
	cin >> n >> k;
	bool ok = true;
	if(n < k) 
		ok = false;
	else if(k % 2 == 0 && n % 2 == 1) {
		ok = false;
	}
	cout << (ok ? "Yes" : "No") << '\n';
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