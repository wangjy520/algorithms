/* 
** Created by Wangjy.
** https://codeforces.com/problemset/problem/1554/C
** 好题
** 从高到底一次考虑该填0还是1
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
	int n, m;
	cin >> n >> m;
	if(m < n) {
		cout << 0 << '\n';
		return ;
	}
	else {
		m++;
		int res = 0;
		for(int i = 30;i >= 0;i--) {
			if(!(n & (1 << i)) && (m & (1 << i))) {
				res |= (1 << i);
			}
			else if((n & (1 << i)) && !(m & (1 << i))) {
				break;
			}
		}
		cout << res << '\n';
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