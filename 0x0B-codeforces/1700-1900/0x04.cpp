/* 
** Created by Wangjy.
** https://codeforces.com/problemset/problem/977/F
** 1700
** 使用map进行dp
** easy
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
	vector<int> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	unordered_map<int, int> m;
	int res = 1;
	int c = a[0];
	m[a[0]] = 1;
	for(int i = 1;i < n;i++) {
		if(m.find(a[i] - 1) != m.end()) {
			int cnt = m[a[i] - 1];
			m[a[i]] = cnt + 1;
			if(m[a[i]] > res) {
				res = m[a[i]];
				c = a[i];
			}
		}
		else {
			m[a[i]] = 1;
		}
	}
	cout << res << '\n';
	for(int i = c - res + 1, j = 0;j < n && i <= c;j++) {
		if(i == a[j]) {
			cout << (j + 1) << " ";
			i++;
		}
	} 
		
	cout <<'\n';
	return 0;
}