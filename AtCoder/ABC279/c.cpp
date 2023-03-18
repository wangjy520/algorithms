// 
// Created by Wangjy.
// 
#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n), t(n);
	for(int i = 0;i < n;i++) {
		cin >> s[i];
	}
	for(int i = 0;i < n;i++) {
		cin >> t[i];
	}
	unordered_map<string, int> mm;
	for(int i = 0;i < m;i++) {
		string str = "";
		for(int j = 0;j < n;j++) {
			str += t[j][i];
		}
		mm[str]++;
	}
	for(int i = 0;i < m;i++) {
		string str = "";
		for(int j = 0;j < n;j++) {
			str += s[j][i];
		}
		mm[str]--;
	}
	int ok = 1;
	for(auto& p : mm) {
		if(p.second != 0) {
			ok = 0;
			break;
		}
	}
	cout << (ok ? "Yes" : "No") << '\n';

	return 0;
}