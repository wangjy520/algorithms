/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 1;i < n;i++) {
		cin >> a[i];
	}
	cout << a[1] << " ";
	for(int i = 1;i < n;i++) {
		if(i < n - 1) {
			if(a[i] <= a[i + 1]) {
				cout << a[i] << " ";
			}
			else {
				cout << a[i + 1] << " ";
			}
		}
		else {
			cout << a[i] << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}