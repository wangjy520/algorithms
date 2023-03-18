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
	vector<int> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	if(n == 1) {
		cout << 0 << '\n';
		return ;
	}
	int res = 1;
	vector<pii> ans;
	ans.emplace_back(make_pair(1, n));
	if((a[0] + a[n - 1]) % 2 == 0) {
		a[0] = a[n - 1];
	}
	for(int i = 2;i < n;i++) {
		res++;
		if((a[i - 1] + a[0]) % 2 == 0) {
			ans.emplace_back(make_pair(i, n));
		}	
		else {
			ans.emplace_back(make_pair(1, i));
		}
	}
	cout << res << '\n';
	for(auto& v : ans) {
		cout << v.first << " " << v.second <<  "\n";
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