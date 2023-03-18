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

	LL a, b;
	cin >> a >> b;
	LL res = 0LL;
	bool ok = false;
	for(int i = 63;i >= 0;i--) {
		//  01
		//  10
		if((a >> i) ^ (b >> i)) {
			res |= (1LL << i);
			ok = true;
		}
		// 00
		else if(!(a >> i) && !(b >> i)) {
			if(ok) {
				res |= (1LL << i);
			}
		}
		// 11
		else {
			if(ok)
				res |= (1LL << i);
		}
	}
	cout << res << '\n';

	return 0;
}