/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	string s, t;
	cin >> s >> t;
	int m = s.size(), n = t.size();
	vector<int> ok(n + 1, 0);
	ok[n] = 1;
	for(int i = n - 1, j = m - 1;i >= 0;i--, j--) {
		if(s[j] == t[i] || s[j] == '?' || t[i] == '?') {
			ok[i] = ok[i + 1];
		}
	}
	cout << (ok[0] ? "Yes" : "No") << '\n';
	int pre = 1;
	for(int i = 0;i < n;i++) {
		int fs = 0;
		if((s[i] == t[i] || s[i] == '?' || t[i] == '?') && pre) {
			if(ok[i + 1]) {
				cout << "Yes" << '\n';
			}
			else {
				cout << "No" << '\n';
			}
		}
		else {
			cout << "No" << '\n';
			pre = 0;
		}
	}


	return 0;
}