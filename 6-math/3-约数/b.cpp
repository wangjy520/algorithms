// 
// Created by Wangjy.
// https://www.luogu.com.cn/problem/P1029
// Accepted
// 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

LL gcd(LL m, LL n) {
	if(m < n)
		return gcd(n, m);
	return m % n == 0 ? n : gcd(n, m % n);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	LL x, y;
	cin >> x >> y;
	LL m = x * y;
	int res = 0;
	for(LL i = 2;i <= y;i++) {
		if(m % i == 0 && gcd(i, m / i) == x) {
			res++;
		}
		
	}	
	cout << res <<'\n';


	return 0;
}