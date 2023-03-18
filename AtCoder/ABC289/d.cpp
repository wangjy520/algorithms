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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	vector<int> b(m);
	unordered_set<int> s;
	for(int i = 0;i < m;i++) {
		cin >> b[i];
		s.insert(b[i]);
	}
	int x;
	cin >> x;
	vector<bool> dp(x + 1, false);
	dp[0] = true;
	for(int i = 1;i <= x;i++) {
		if(s.find(i) == s.end()) {
			for(int j = 0;j < n;j++) {
				if(i - a[j] >= 0) {
					dp[i] = dp[i] || dp[i - a[j]];
				}
			}
		}
	}
	
	cout << (dp[x] ? "Yes" : "No") << '\n';

	return 0;
}