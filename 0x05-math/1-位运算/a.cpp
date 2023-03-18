// 
// Created by Wangjy.
// https://www.luogu.com.cn/problem/P5657
// Accepted
// 格雷码的生成方法
// 实际上应该是一个模拟题目
// 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	LL n, k;
	cin >> n >> k;
	string s = "";
	while(n >= 1) {
		LL half = pow(2, n - 1);
		if(k < half) {
			s += "0";
		}
		else {
			s += "1";
			k = half - 1 - k + half;
		}
		n--;
	}
	cout << s << '\n';


	return 0;
}