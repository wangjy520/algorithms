/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;


void solve() {
	int a, b;
	cin >> a >> b;
	cout << 2 << '\n';
	cout << 1 << " " << b - 1 << '\n';
	cout << a << " " << b << '\n';	
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