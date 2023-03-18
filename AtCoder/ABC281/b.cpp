#include<bits/stdc++.h>
using namespace std;

int main () {
	string s;
	cin >> s;
	int n = s.size();
	int ok = 1;
	if(n != 8) {
		ok = 0;
	}
	else {
		if(!(s[0] >= 'A' && s[0] < 'Z') || !(s[n - 1] >= 'A' && s[n - 1] <= 'Z')) {
			ok = 0;
		}
		else {
			if(s[1] == '0') {
				ok = 0;
			}
			else 
				for(int i = 1;i < n - 1;i++) {
					if(s[i] < '0' || s[i] > '9') {
						ok = 0;
						break;
					}
				}
		}
	}
	cout << (ok ? "Yes" : "No") << '\n';

	return 0;
}