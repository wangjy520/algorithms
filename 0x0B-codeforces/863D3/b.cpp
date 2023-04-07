/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	if(a > n / 2)
		a = n - a + 1;
	if(b > n / 2)
		b = n - b + 1;
	if(c > n / 2)
		c = n - c + 1;
	if(d > n / 2)
		d = n - d + 1;
	int x = min(a, b), y = min(c, d);
	cout << abs(x - y) << '\n';
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