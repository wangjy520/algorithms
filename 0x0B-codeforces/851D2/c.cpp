/* 
** Created by Wangjy.
** 
** 
** 
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
	if(n % 2 == 0) {
		cout << "No" << '\n';
	}
	else {
		int l = 1, r = n * 2;
		unordered_set<int> s;
		cout << "Yes\n";
		while(l < r) {
			s.insert(l);
			s.insert(r);
			cout << l << " " << r << '\n';
			l += 2;
			r--;
		} 
		for(int i = 1;i <= n * 2;i++) {
			if(s.find(i) == s.end()) {
				while(s.find(r) != s.end()) {
					r--;
				}
				cout << i << " " << r << '\n';
				s.insert(i);
				s.insert(r);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	


	return 0;
}