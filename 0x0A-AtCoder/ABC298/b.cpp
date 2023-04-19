/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			cin >> b[i][j];
		}
	}
	bool res = false;
	for(int k = 0;k < 4;k++) {
		vector<vector<int>> c(n, vector<int>(n));
		bool ok = true;
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < n;j++) {
				c[i][j] = a[n - j - 1][i];
				if(b[i][j] && !c[i][j]) {
					ok = false;
				}
			}
		}
		res = res || ok;
		a = c;
	}
	cout << (res ? "Yes" : "No") << '\n';

	return 0;
}