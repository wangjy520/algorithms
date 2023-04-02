/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> a(8);
	int row = -1, col = -1;
	for(int i = 0;i < 8;i++) {
		cin >> a[i];
		for(int j = 0;j < 8;j++) {
			if(a[i][j] == '*') {
				row = i;
				col = j;
			}
		}
	}
	cout << char(col + 'a') << (8 - row) << '\n';

	return 0;
}