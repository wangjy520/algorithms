/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

vector<long long> solve(long long n) {
	string s = to_string(n);
	int m = s.size();
	vector<long long> res(10, 0);

	for(int k = 0;k < 10;k++) {
		vector<vector<long long>> dp(m, vector<long long>(m + 1, -1));

		function<long long(int, int, bool, bool)> f = [&](int i, int c, bool is_num, bool is_limit) -> long long {
			if(i >= m) {
				return is_num ? c : 0;
			}
			if(is_num && !is_limit && dp[i][c] != -1)
				return dp[i][c];
			long long ans = 0;
			if(!is_num)  {
				ans = f(i + 1, c, false, false);
			}
			for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 9);d++) {
				ans += f(i + 1, c + (d == k), true, (is_limit && d == s[i] - '0'));
			}
			if(is_num && !is_limit)
				dp[i][c] = ans;
			return ans;
		};

		res[k] = f(0, 0, false, true);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b;
	cin >> a >> b;
	while(a && b) {
		if(a > b)
			swap(a, b);
		vector<long long> sa = solve(a - 1);
		vector<long long> sb = solve(b);
		for(int k = 0;k < 10;k++) {
			cout << sb[k] - sa[k] << " ";
		}
		cout << '\n';
		cin >> a >> b;
	}

	return 0;
}