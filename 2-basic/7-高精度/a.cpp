// 
// Created by Wangjy.
// 高精度加法
// https://www.luogu.com.cn/problem/P1601
// Accepted
// 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

string add(string a, string b) {
	string res = "";
	int c = 0, s = 0, sum = 0;
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
		sum = (c + num1 + num2);
		s = sum % 10;
		c = sum / 10;
		res = to_string(s) + res;
	}
	if(c != 0)
		res = to_string(c) + res;
	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	
	cout << add(a, b) << '\n';


	return 0;
}