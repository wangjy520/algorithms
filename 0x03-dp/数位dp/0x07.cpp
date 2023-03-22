	/* 
	** Created by Wangjy.
	*/ 
	#include<bits/stdc++.h>
	using namespace std;
	int dp[10][64][1 << 10];

	string convert(long long num, int k) {
		string s = "";
		while(num > 0) {
			int c = num % k;
			s += c + '0';
			num /= k;
		}
		reverse(s.begin(), s.end());
		return s;
	}

	long long solve(long long n, int k) {
		string s = convert(n, k);
		int m = s.size();

		function<long long(int, int, bool, bool)> f = [&](int i, int mask, bool is_num, bool is_limit) -> long long {
			if(i >= m) {
				return is_num && !mask;
			}
			if(is_num && !is_limit && dp[k - 1][i][mask] != -1) {
				return dp[k - 1][i][mask];
			}
			long long ans = 0;
			if(!is_num) {
				ans = f(i + 1, mask, false, false);
			}
			for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : k - 1);d++) {
				ans += f(i + 1, mask ^ (1 << d), true, (is_limit && d == s[i] - '0'));
			}
			if(is_num && !is_limit)
				dp[k - 1][i][mask] = ans;
			return ans;
		};

		return f(0, 0, false, true);
	}

	void solve() {
		int k;
		long long a, b;
		cin >> k >> a >> b;
		cout << solve(b, k) - solve(a - 1, k) << '\n';
	}

	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);

		memset(dp, -1, sizeof(dp));
		int t;
		cin >> t;
		while(t--) {
			solve();
		}
		


		return 0;
	}