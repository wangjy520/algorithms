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
	string s = to_string(n);
	string x = "", y = "";
	bool fs = true;
	for(int i = 0;i < s.size();i++) {
		if((s[i] - '0') % 2 == 0) {
			x += (s[i] - '0') / 2 + '0';
			y += (s[i] - '0') / 2 + '0';
		}
		else {
			x += (s[i] - '0') / 2 + (fs ? 1 : 0) + '0';
			y += (s[i] - '0') / 2 + (fs ? 0 : 1) + '0';
			fs = !fs;
		}
	}
	cout << stoi(x) << ' ';
	cout << stoi(y) << '\n';
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