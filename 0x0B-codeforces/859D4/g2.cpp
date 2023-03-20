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
	sort(a.begin(), a.end());
	if(a[0] != 1) {
		cout << "No" << '\n';
		return ;
	}
	LL far = 1;
	bool ok = true;
	for(int i = 1;i < n;i++) {
		if(far >= a[i]) {
			far += a[i];
		}
		else {	
			ok = false;
			break;
		}
	}
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