/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	bool ok1 = false, ok2 = true;
	for(int i = 0;i < n;i++) {
		if(s[i] == 'o') {
			ok1 = true;
		}
		if(s[i] == 'x') {
			ok2 = false;
		}
	}
	if(ok1 && ok2) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

	return 0;
}