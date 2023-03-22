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

bool check(int mask, int h) {
	int i = 0;
	while(h > 0) {
		if(h & 1) {
			if(i % 2 == 0 && !((mask >> i) & 1))
				return false;
			if(i % 2 == 1 && ((mask >> i) & 1))
				return false;
		}
		i++;
		h >>= 1;
	}
	return true;
}

ULL solve(ULL n) {
	string s = to_string(n);
	int m = s.size();
	vector<vector<vector<ULL>>> dp(m, vector<vector<ULL>>(1 << 10, vector<ULL>(1 << 10, -1)));
	function<ULL(int, int, int, bool, bool)> f = [&](int i, int mask, int h, bool is_num, bool is_limit) -> ULL {
		if(i >= m) {
			return is_num && check(mask, h);
		}
		if(is_num && !is_limit && dp[i][mask][h] != -1)
			return dp[i][mask][h];
		ULL ans = 0;
		if(!is_num)
			ans = f(i + 1, mask, h, false, false);
		for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 9);d++) {
			ans += f(i + 1, mask ^ (1 << d), h | (1 << d), true, is_limit && (d == s[i] - '0'));
		}
		if(is_num && !is_limit)
			dp[i][mask][h] = ans;
		return ans;
	};
	return f(0, 0, 0, false, true);
}

void solve() {
	ULL a, b;
 	cin >> a >> b;
	cout << solve(b) - solve(a - 1) << '\n';
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