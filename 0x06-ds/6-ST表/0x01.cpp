/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> nums(n);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
	}
	int t = log(n) / log(2) + 1;
	vector<vector<int>> f(n, vector<int>(t, 0x3f3f3f3f));
	for(int i = 0;i < n;i++) {
		f[i][0] = nums[i];
	}
	for(int j = 1;j < t;j++) {
		for(int i = 0;i <= (n - (1 << j));i++) {
			f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
	int len = log(m) / log(2);
	for(int i = 0;i < n - m + 1;i++) {

		cout << min(f[i][len], f[i + m - (1 << len)][len]) << '\n';
	}
	


	return 0;
}