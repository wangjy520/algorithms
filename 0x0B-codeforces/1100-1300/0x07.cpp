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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	int res = 0;
	int s = 0;
	int sum = 0;
	int l = 0, r = 0;
	while(r < k) {
		sum += a[r++];
	}
	s = sum;
	while(r < n) {
		sum += a[r++];
		sum -= a[l++];
		if(sum < s) {
			s = sum;
			res = l;
		}
	}
	cout << res + 1 << '\n';

	return 0;
}