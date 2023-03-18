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
	int sum = 0;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
		sum += nums[i] - 1;
	}
	if(sum % 2 == 1) {
		cout << -1 << '\n';
	}
	else {
		int s = 0;
		for(int i = 0;i < n - 1;i++) {
			s += nums[i] - 1;
			if(s == sum / 2) {
				cout << i + 1 << '\n';
				return ;
			}
		}
	}
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