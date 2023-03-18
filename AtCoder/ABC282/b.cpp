#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	vector<int> b(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		int mask = 0;
		for(int j = 0;j < m;j++) {
			if(a[i][j] == 'o') {
				mask |= (1 << (m - j - 1));
			}
		}
		b[i] = mask;
	}
	int res = 0;
	for(int i = 0;i < n;i++) {
		for(int j = i + 1;j < n;j++) {
			if((b[i] | b[j]) == (1 << (m)) - 1)
				res++;
		}
	}
	cout << res << '\n';

	return 0;
}