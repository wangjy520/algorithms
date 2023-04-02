/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, m;
	cin >> n >> m;
	long long res = -1;
	for(int i = 1;i <= n;i++) {
		if((m + i - 1) / i <= n) {
			long long s = (long long) i * ((m + i - 1) / i);
			if(s >= m)
				res = (res == -1 ? s : min(res, s));
		}
		if((m + i - 1) / i < i) {
			break;
		}
	}
	cout << res << '\n';
	return 0;
}	