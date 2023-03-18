// 
// Created by Wangjy.
// https://www.luogu.com.cn/problem/P2158
// Accpted
/*
assume p(x, y), c(0, 0),
how many different slopes are there, except for two spacial cases?
y / x
think about each column, 





*/
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	if(n == 1) {
		cout << 0 << '\n';
		return 0;
	}
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
			v[i * prime[j]] = prime[j];
			if(i % prime[j] == 0) {
				g[i * prime[j]] = prime[j] * g[i];
			}
			else {
				g[i * prime[j]] = (prime[j] - 1) * g[i];
			}
		}
	}
	
	LL sum = 0;
	for(int i = 0;i <= n - 1;i++)
		sum += g[i];
	cout << (sum * 2 + 1) << '\n';

	return 0;
}