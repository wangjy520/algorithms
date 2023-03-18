// 
// Created by Wangjy.
// https://www.luogu.com.cn/problem/P1075
// Accepted
// 暴力
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
	for(int i = 2;i <= sqrt(n);i++) {
		if(n % i == 0) {
			cout << n / i << '\n';
			break;
		}
	}	


	return 0;
}