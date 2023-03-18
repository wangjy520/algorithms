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
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	t += s;
	int cnt = 0;
	for(int i = 1;i < m + n;i++) {
		if(t[i] == t[i - 1])
			cnt++;
	}
	cout << (cnt <= 1 ? "Yes" : "NO") << '\n';
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