// 
// Created by Wangjy.
// https://www.luogu.com.cn/problem/P5514
// Accepted
// 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int res = 0;
	for(int i = 0;i < n;i++) {
		int a;
		cin >> a;
		res ^= a;
	}
	cout << res << '\n';


	return 0;
}