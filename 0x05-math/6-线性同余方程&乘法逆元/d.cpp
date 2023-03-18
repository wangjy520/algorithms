/* 
** Created by Wangjy.
** 同余方程
** Accepted
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

pll exgcd(LL a, LL b) {
	if(b == 0) {
		return make_pair(1L, 0);
	}
	pll ans = exgcd(b, a % b);
	return make_pair(ans.second, ans.first - (a / b) * ans.second);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	LL a, b;
	cin >> a >> b;
	cout << (exgcd(a, b).first + b) % b << '\n';
	


	return 0;
}