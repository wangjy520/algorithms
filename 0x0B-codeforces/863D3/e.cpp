/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

bool check(long long mid, long long n, vector<long long>& cnt) {
	int j = 18;
	long long num = mid;
	long long ans = 0;
	while(mid > 0) {
		long long mask = pow(10, j);
		if(mask <= mid) {
			int a = mid / mask;
			if(a >= 4) {
				ans += a * cnt[j - 1];
			}
			else {
				ans += (a + 1) * cnt[j - 1];
			}
			mid -= mask * a;
		}
		j--;
	}
	// cout << ans << '\n';
	return n >= (num - ans);
}

void solve(vector<long long>& cnt) {
	long long n;
	cin >> n;
	
	long long l = 1, r = 1e18;
	while(l < r) {
		long long mid = (l + r) >> 1;
		if(check(mid, n, cnt)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<long long> cnt(19, 0);
	cnt[1] = 1;
	for(int i = 2;i <= 18;i++) {
		cnt[i] = pow(10, i - 1) + cnt[i - 1] * 8;
		for(int j = i - 2;j >= 1;j--) {
			cnt[i] += cnt[j];
		}
	}
	int t;
	cin >> t;
	while(t--) {
		solve(cnt);
	}

	return 0;
}