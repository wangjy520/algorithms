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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	LL n, k;
	cin >> n >> k;
	LL res = n * k;
	LL i = 1, j = k / (k / i);
	// 1, 
	while(j <= n) {
		// cout << i << " " << j << '\n';
		// res -= (k / i) * ((i + j) * (j - i + 1) / 2);
		i = j + 1;
		// j = k / (k / i);
		j = i + 1;
	}
	cout << res << '\n';

	return 0;
}