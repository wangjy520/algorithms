/* 
* Created by Wangjy.
* https://www.luogu.com.cn/problem/P2398
* Accepted
* 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	LL n;
	cin >> n;
	vector<int> v(n + 1, 0);
	vector<int> g(n + 1, 0);
	g[1] = 1;
	vector<int> prime;
	int cnt = 0;

	for(int i = 2;i <= n;i++) {
		if(v[i] == 0) {
			v[i] = i;
			g[i] = i - 1;
			prime.push_back(i);
			cnt++;
		}
		for(int j = 0;j < cnt;j++) {
			if(prime[j] > n / i || prime[j] > v[i])
				break;
			v[prime[j] * i] = prime[j];
			if(i % prime[j] == 0)
				g[i * prime[j]] = g[i] * prime[j];
			else 
				g[i * prime[j]] = g[i] * (prime[j] - 1);
		}
	}

	LL s = 0;
	for(int i = 1;i <= n;i++) {
		s += ((n / i) * (n / i)) * g[i];
	}
	cout << s << '\n';


	return 0;
}