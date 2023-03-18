/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

vector<int> euler(int n) {
	vector<int> phi(n + 1), v(n + 1), prime;
	iota(v.begin(), v.end(), 0);
	int cnt = 0;
	for(int i = 2;i <= n;i++) {
		if(v[i] == i) {
			prime.push_back(i);
			cnt++;
			phi[i] = i - 1;
		}
		for(int j = 0;j < cnt;j++) {
			if(prime[j] > i || prime[j] > n / i)
				break;
			v[i * prime[j]] = prime[j];
			phi[i * prime[j]] = phi[i] * (i % prime[j] ? (prime[j] - 1) : prime[j]);
		}
	}
	return phi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	if(n == 0 || n == 1) {
		cout << 0 << '\n';
		return 0;
	}
	vector<int> nums = euler(n - 1);
	int res = 0;
	for(int i = 2;i < n;i++) {
		res += nums[i];
	}
	cout << (3 + 2 * res) << '\n';

	return 0;
}