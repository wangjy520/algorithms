/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		if(i > 0) {
			if(a[i] - a[i - 1] <= d) {
				cout << a[i] << '\n';
				return 0;
			}
		}
	}
	cout << -1 << '\n';


	return 0;
}