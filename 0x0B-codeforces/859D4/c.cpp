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

bool func(string s, int a) {
	int n = s.size();
	vector<int> cnt(26, -1);
	for(int i = 0;i < n;i++) {
		if(cnt[s[i] - 'a'] == -1) {
			cnt[s[i] - 'a'] = a;
		}
		else if(cnt[s[i] - 'a'] != a) {
			return false;
		}
		a = 1 - a;
	}
	return true;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool ok = func(s, 0) || func(s, 1);
	cout << (ok ? "Yes" : "No") << '\n';
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