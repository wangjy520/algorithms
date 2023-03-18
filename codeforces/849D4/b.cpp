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
	int i = 0, j = 0;
	for(int k = 0;k < n;k++) {
		if(s[k] == 'U') {
			j++;
		}
		else if(s[k] == 'D') {
			j--;
		}
		else if(s[k] == 'L') {
			i--;
		}
		else {
			i++;
		}
		if(i == 1 && j == 1) {
			cout << "Yes" << '\n';
			return ;
		}
	}
	cout << "No" << '\n';
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