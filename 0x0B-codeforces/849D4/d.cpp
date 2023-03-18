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

void solve() {
	int n;
	string s;
	cin >> n >> s;
	unordered_map<char, int> m1, m2;
	for(int i = n - 1;i >= 0;i--) {
		m2[s[i]]++;
	}
	
	int res = m2.size();
	for(int i = 0;i < n;i++) {
		m1[s[i]]++;
		if(m2[s[i]] == 1) {
			m2.erase(s[i]);
		}
		else {
			m2[s[i]]--;
		}
		res = max(res, (int) m1.size() + (int) m2.size());
	}
	cout << res << '\n';
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