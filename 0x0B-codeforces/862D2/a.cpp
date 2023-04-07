/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int mask = 0;
	for(int i = 0;i < n;i++) {
		int a;
		cin >> a;
		mask ^= a;
	}
	bool ok = false;
	if(mask == 0) {
		ok = true;
	}
	else if(n % 2 == 1) {
		ok = true;
	}
	if(ok) {
		cout << mask << '\n';
	}
	else {
		cout << -1 << '\n';
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