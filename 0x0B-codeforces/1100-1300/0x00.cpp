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
	for(int &i : a) {
		cin >> i;
	}
	int mx = n, mn = 1;
	int l = 0, r = n - 1;
	while(l < r) {
		if(a[l] == mx) {
			l++;
			mx--;
		}
		else if(a[l] == mn) {
			l++;
			mn++;
		}
		else if(a[r] == mn) {
			r--;
			mn++;
		}
		else if(a[r] == mx) {
			r--;
			mx--;
		}
		else break;
	}
	if(l == r) {
		cout << -1 << '\n';
	}
	else {
		cout << (l + 1) << " " << (r + 1) << '\n';
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