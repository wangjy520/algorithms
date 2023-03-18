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
	string t = "314159265358979323846264338327";
	string s;
	cin >> s;
	int res = 0;
	for(int i = 0;i < s.size();i++) {
		if(s[i] == t[i]) {
			res++;
		}
		else {
			break;
		}
	}
	cout << res << '\n';
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