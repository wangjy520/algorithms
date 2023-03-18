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
	string s;
	cin >> n >> s;
	int l = 0, r = n - 1;
	bool ok = false;
	bool pre = true;
	while(l < r) {
		if(s[l] != s[r]) {
			if(!pre) {
				if(ok) {
					cout << "no" << '\n';
					return ;
				}
				else {
					ok = true;
				}
			}
			pre = true;
		}
		else {
			pre = false;
		}
		l++;
		r--;
	}
	cout << "Yes" << '\n';
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