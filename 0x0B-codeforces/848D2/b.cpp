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

// 智商不够，事件来凑

void solve() {
	int n, m, d;
	cin >> n >> m >> d;
	vector<int> p(n), a(m), pos(n + 1);
	for(int i = 0;i < n;i++) {
		cin >> p[i];
		pos[p[i]] = i;
	}

	int res = n + 1;
	
	for(int i = 0;i < m;i++) {
		cin >> a[i];
	}
	for(int i = 0;i < m - 1;i++) {
		if(pos[a[i]] >= pos[a[i + 1]] || pos[a[i + 1]] > pos[a[i]] + d) {
			cout << 0 << '\n';
			return ;
		}
		else {
			int ans = n + 1;
			if(pos[a[i]] + n - pos[a[i + 1]] - 1 >= pos[a[i]] + d - pos[a[i + 1]] + 1)
				ans = min(ans, pos[a[i]] + d - pos[a[i + 1]] + 1);
			ans = min(ans, pos[a[i + 1]] - pos[a[i]]);
			res = min(res, ans);
		}
	}
	cout << res << '\n';
	

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