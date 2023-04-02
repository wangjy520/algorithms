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
	string s = "";
	int cnt = 0;
	while(n != 1 && cnt < 40) {
		if(n % 2 == 0) {
			cout << -1 << '\n';
			return ;
		}
		else {
			if((n + 1) / 2 % 2 == 1) {
				n = (n + 1) / 2;
				s += '1';
			}
			else {
				n = (n - 1) / 2;
				s += '2';
			}
			cnt++;
		}
	}
	if(n == 1) {
		cout << cnt << '\n';
		for(int i = s.size() - 1;i >= 0;i--) {
			cout << s[i] << " ";
		}
		cout << '\n';
	}
	else {
		cout << -1 << '\n';
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