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
	char ch;
	cin >> ch;
	if(ch == 'c' || ch =='o' || ch == 'd' || ch == 'e' || ch == 'f' || ch == 'r' || ch == 's') {
		cout << "Yes" << '\n';
	}
	else {
		cout << "No" << '\n';
	}
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