/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

unordered_map<int, int> prime(int n) {
	unordered_map<int, int> res;
	for(int i = 2;i <= sqrt(n);i++) {
		if(n % i == 0) {
			int cnt = 0;
			while(n % i == 0) {
				cnt++;
				n /= i;
			}
			res[i] = cnt;
		}
	}
	if(n > 1) {
		res[n] = 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// (m1 ^ m2) | (s ^ n), 求最小的n
	int n;
	int m1, m2;
	cin >> n >> m1 >> m2;
	vector<int> s(n);
	for(int i = 0;i < n;i++) {
		cin >> s[i];
	}
	unordered_map<int, int> pm1 = prime(m1);
	// for(auto& p : pm1) {
	// 	cerr << p.first << " " << p.second << '\n';
	// }
	int res = 0x3f3f3f3f;
	for(int i = 0;i < n;i++) {
		unordered_map<int, int> ps = prime(s[i]);
		bool fs = true;
		long long k = 0;
		for(auto& p : pm1) {
			if(ps.find(p.first) == ps.end()) {
				fs = false;
				break;
			}
			else {
				k = max(k, ((long long)p.second * m2 + ps[p.first] - 1) / ps[p.first]);
			}
		}

		
		if(fs) {
			// cerr << s[i] << " " << k << '\n';
			res = min(res, (int) k);
		}
	}
	cout << (res == 0x3f3f3f3f ? -1 : res) << '\n';

	return 0;
}