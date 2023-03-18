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
	vector<int> a(n * n);
	int num1 = 1, num2 = n * n;
	for(int i = 0, j = 1;(i < n * n) || (j < n * n);i += 2, j += 2) {
		if(i < n * n)
			a[i] = num1++;
		if(j < n * n)
			a[j] = num2--;
	}
	
	vector<vector<int>> res(n, vector<int>(n));
	int cnt = 0;
	for(int i = 0;i < n;i++) {
		if(i & 1) {
			for(int j = 0;j < n;j++) {
				res[i][j] = a[cnt++];
			}
		}
		else {
			for(int j = n - 1;j >= 0;j--) {
				res[i][j] = a[cnt++];
			}
		}
	}
	for(auto& v : res) {
		for(auto& vv : v) {
			cout << vv << " ";
		}
		cout << '\n';
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