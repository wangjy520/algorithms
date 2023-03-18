/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int l = 0, r = n - 1;
	while(l < r) {
		if((s[l] - '0') ^ (s[r] - '0') == 1) {
			l++;
			r--;
		}
		else {
			break;
		}
	}
	cout << r - l + 1 << '\n';
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