/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, d;
	cin >> n >> d;
	string s;
	cin >> s;
	for(int i = 0;i < n;i++) {
		if(d > s[i] - '0') {
			cout << s.substr(0, i) << d << s.substr(i) << '\n';
			return ;
		}
	}
	cout << s << d << '\n';
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