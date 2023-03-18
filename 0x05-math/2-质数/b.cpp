// 
// Created by Wangjy.
// 线性筛
// Accepted
// 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> v(n + 1, 0);
	vector<int> prime;
	int cnt = 0;

	for(int i = 2;i <= n;i++) {
		if(v[i] == 0) {
			v[i] = i;
			prime.push_back(i);
			cnt++;
		}
		for(int j = 0;j < cnt;j++) {
			if(prime[j] > n / i || prime[j] > v[i])
				break;
			v[i * prime[j]] = prime[j];
		}
	}
	for(int i = 0;i < q;i++) {
		int k;
		cin >> k;
		cout << prime[k - 1] << '\n';
	}

	return 0;
}