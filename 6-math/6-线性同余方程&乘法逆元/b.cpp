/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

pii exgcd(LL a, LL b) {
	if(b == 0) {
		return make_pair(1, 0);
	}
	pii ans = exgcd(b, a % b);
	return make_pair(ans.second, ans.first - (a / b) * ans.second);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	LL a, b;
	cin >> a >> b;
	pii res = exgcd(a, b);
	LL ans = res.first;
	while(ans < 0) {
		ans += b;
	}
	cout << ans << '\n';


	return 0;
}