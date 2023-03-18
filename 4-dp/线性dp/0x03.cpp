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

int compare(string s, string t) {
	if(s.size() > t.size())
		return 1;
	else if(s.size() < t.size()) 
		return -1;
	else 
		return s.compare(t);
}

string mul(string a, string b) {
	int m = a.size(), n = b.size();
	vector<int> res(m + n, 0);
	for(int i = m - 1;i >= 0;i--) {
		for(int j = n - 1;j >= 0;j--) {
			res[i + j + 1] += (a[i] - '0') *(b[j] - '0');
		}
	}
	for(int i = m + n - 1;i > 0;i--) {
		res[i - 1] += res[i] / 10;
		res[i] %= 10;
	}
	string s = "";
	for(int i = m + n - 1;i >= 1;i--) {
		s += (char) (res[i] + '0');
	}
	if(res[0] != 0)
		s += (char) (res[0] + '0');
	reverse(s.begin(), s.end());
	return s;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<vector<string>> dp(n, vector<string>(k + 2, "0"));
	dp[0][1] = s[0];
	for(int i = 1;i < n;i++) {
		dp[i][1] = s.substr(0, i + 1);
		for(int m = 2;m <= k + 1;m++) {
			for(int j = i - 1;j >= 0;j--) {
				if(j + 1 >= m - 1) {
					string ans = mul(dp[j][m - 1], s.substr(j + 1, i - j));
					if(compare(ans, dp[i][m]) > 0) {
						dp[i][m] = ans;
					}
				}
				else {
					break;
				}
			}
		}
	}
	// for(int i = 0;i < n;i++) {
	// 	for(int j = 1;j <= k + 1;j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << '\n';
	// }
	cout << dp[n - 1][k + 1] << '\n';
	// cout << compare("39", "31") << '\n';

	return 0;
}