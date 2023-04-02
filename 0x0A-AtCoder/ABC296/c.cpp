/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	unordered_set<int> s;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	for(int i = 0;i < n;i++) {
		if(s.find(a[i] + x) != s.end()) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";

	return 0;
}