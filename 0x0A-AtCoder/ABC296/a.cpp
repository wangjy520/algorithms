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
	for(int i = 1;i < n;i++) {
		if(s[i] == s[i - 1]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";

	return 0;
}