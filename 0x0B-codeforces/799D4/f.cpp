/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	vector<vector<bool>> left(n, vector<bool>(10, false)), right(n, vector<bool>(10, false));
	right[n - 1][a[n - 1] % 10] = true;
	for(int i = n - 2;i >= 0;i--) {
		for(int j = 0;j < 10;j++) {
			if(j != a[i] % 10) 
				right[i][j] = right[i + 1][j];
			else 
				right[i][j] = true;
		}
	}
	left[0][a[0] % 10] = true;
	for(int i = 1;i < n - 1;i++) {
		int mod = a[i] % 10;
		for(int j = 0;j < 10;j++) {
			if(left[i - 1][j])
				if(right[i + 1][(3 - (mod + j) + 20) % 10]) {
					cout << "YES" <<'\n';
					return ;
				}
		}
		for(int j = 0;j < 10;j++) {
			if(j != a[i] % 10)
				left[i][j] = left[i - 1][j];
			else 
				left[i][j] = true;
		}
	}
	cout << "NO" << '\n';
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