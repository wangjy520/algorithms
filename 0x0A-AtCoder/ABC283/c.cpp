#include<bits/stdc++.h>
using namespace std;

int main() {
	
	string s;
	cin >> s;
	int res = 0;
	int cnt = 0;
	for(auto ch : s) {
		if(ch == '0') {
			cnt++;
		}
		else {
			res += (cnt + 1) / 2;
			res ++ ;
			cnt = 0;
		}
	}
	res += (cnt + 1) / 2;
	cout << res << '\n';

	return 0;
}