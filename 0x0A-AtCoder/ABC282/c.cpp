#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	int cnt = 0;
	for(int i = 0;i < n;i++) {
		if(s[i] == '"') {
			cnt++;
		}
		else if(s[i] == ',') {
			if(cnt % 2 == 0) {
				s[i] = '.';
			}
		}
	}
	cout << s << '\n';

	return 0;
}