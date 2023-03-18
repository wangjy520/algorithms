/* 
** Created by Wangjy.
** 线性求逆元
** Accepted
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, p;
	cin >> n >> p;
	vector<int> inv(n + 1);
	inv[1] = 1;
	cout << 1 << '\n';
	for(int i = 2;i <= n;i++) {
		inv[i] = (LL) (- p / i + p) * inv[p % i] % p;
		cout << inv[i] << '\n';
	}
	


	return 0;
}