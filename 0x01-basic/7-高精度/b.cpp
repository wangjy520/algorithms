// 
// Created by Wangjy.
// https://www.luogu.com.cn/problem/P2142
// 高精度减法，两个整数相减
// Accepted
// 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int compare(string s, string t) {
	if(s.size() > t.size())
		return 1;
	else if(s.size() < t.size())
		return -1;
	else return s.compare(t);
}

string solve(string a, string b) {
	int c = compare(a, b);
	if(c < 0) {
		return "-" + solve(b, a);
	}
	else if(c == 0) {
		return "0";
	}
	else {
		string res = "";
		int s = 0, c = 0, sum = 0;
		int i = a.size() - 1, j = b.size() - 1;
		while(i >= 0 || j >= 0) {
			int num1 = 0, num2 = 0;
			if(i >= 0) {
				num1 = a[i] - '0';
				i--;
			}
			if(j >= 0) {
				num2 = b[j] - '0';
				j--;
			}
			sum = (num1 - num2 - c);
			if(sum < 0) {
				c = 1;
				sum += 10;
			}
			else 
				c = 0;
			s = sum % 10;
			res = to_string(s) + res;
		}
		int cnt = 0;
		while(cnt < res.size()) {
			if(res[cnt] == '0')
				cnt++;
			else 
				break;
		}
		return res.substr(cnt, res.size() - cnt);
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	cout << solve(a, b) << '\n';


	return 0;
}