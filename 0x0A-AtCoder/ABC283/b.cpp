#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	for(int i = 0;i < m;i++) {
		int t, k;
		cin >> t >> k;
		if(t == 1) {
			int x;
			cin >> x;
			a[k - 1] = x;
		}
		else {
			cout << a[k - 1] << '\n';
		}
	}

	return 0;
}