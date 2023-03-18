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
typedef pair<long long, long long> pll;

pll exgcd(LL a, LL b) {
	if(b == 0) {
		return make_pair(1L, 0);
	}
	pll ans = exgcd(b, a % b);
	return make_pair(ans.second, ans.second - (a / b) * ans.first);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	LL n, p, k;
	cin >> n >> p >> k;
	vector<LL> nums(n);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
	}
	vector<LL> pre(n + 1, 1);
	for(int i = 1;i <= n;i++) {
		pre[i] = (pre[i - 1] * nums[i - 1]) % p;
	}
	vector<LL> s(n), res(n);
	s[n - 1] = (exgcd(pre[n], p).first + p) % p;
	for(int i = n - 1;i >= 0;i--) {
		res[i] = (pre[i] * s[i] + p) % p;
		if(i > 0) {
			s[i - 1] = (nums[i] * s[i] + p) % p;
		}
	}
	LL ans = 0;
	for(int i = 0;i < n;i++) {
		ans = (ans + k * res[i]) % p;
		k = k * k % p;
	}
	cout << ans << '\n';
	


	return 0;
}