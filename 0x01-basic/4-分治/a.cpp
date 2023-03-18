// 
// Created by Wangjy.
// https://www.luogu.com.cn/problem/P1010
// 分治
// Accepted
// 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

string solve(int n) {
	if(n <= 2)
		return to_string(n);
	string res = "";
	int cnt = 15;
	int cur = pow(2, 15);
	while(n > 0) {
		if(n >= cur) {
			n -= cur;
			string p = solve(cnt);
			if(p != "1")
				res += "2(" + p + ")+";
			else 
				res += "2+";
		}
		cur /= 2;
		cnt--;
	}
	return res.substr(0, res.size() - 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	// cout << n << '\n';
	cout << solve(n) << '\n';


	return 0;
}