// 
// Created by Wangjy.
// 
#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	bool ok = false;
	if(s == t)
		ok = true;
	else if(t.size() > s.size()) {
		ok = false;
	}
	else {
		for(int i = 0;i <= s.size() - t.size();i++) {
			if(s.substr(i, t.size()) == t) {
				ok = true;
				break;
			}
		}
	}
	cout << (ok ? "Yes" : "No") << '\n';

	return 0;
}