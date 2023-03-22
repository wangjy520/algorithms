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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	LL res = 0;
	string s =  to_string(n);
	int m = s.size();
	vector<vector<LL>> dp(m, vector<LL>(82, -1));

	function<LL(int, int, bool, bool)> f = [&](int i, int c, bool is_num, bool is_limit) -> LL {
		if(i >= m) {
			return is_num ? c : 0;
		}
		if(!is_limit && is_num && dp[i][c] != -1)
			return dp[i][c];
		LL ans = 0;
		if(!is_num)
			ans = f(i + 1, c, false, false);
		for(int d = (is_num ? 0 : 1);d <= (is_limit ? s[i] - '0' : 9);d++) {
			ans += f(i + 1, c + d, true, is_limit && (d == s[i] - '0'));
		}
		if(!is_limit && is_num)
			dp[i][c] = ans;
		return ans;
	};
	cout << f(0, 0, false, true) << '\n';

	return 0;
}