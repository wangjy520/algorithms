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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	vector<int> res;
	vector<int> v(n + 1, 0);
	for(int i = 1;i <= n;i++) {
		if(!v[i]) {
			v[a[i]] = 1;
		}
	}
	for(int i = 1;i <= n;i++) {
		if(!v[i]) {
			res.push_back(i);
		}
	}
	cout << res.size() << '\n';
	for(auto& ans : res) {
		cout << ans << " ";
	}
	cout << '\n';

	return 0;
}