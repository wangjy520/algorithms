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
	string s;
	cin >> s;
	unordered_set<int> ss;
	int n = s.size();
	int ans = 0;
	for(int i = 0;i < n;i++) {
		if(ss.size() == 3 && ss.find(s[i]) == ss.end()) {
			ans++;
			ss.clear();
			
		}
		ss.insert(s[i]);
	}
	ans += ss.size() > 0;
	cout << ans << '\n';
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