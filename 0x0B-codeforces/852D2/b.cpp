/* 
** Created by Wangjy.
** -2 -1 0 1 2 3 2 1 0 -1
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

void solve() {
	LL a, b;
	cin >> b >> a;
	long long len = (b - a) * 2;
	cout << len << '\n';
	for(int i = a;i <= b;i++)
		cout << i << " ";
	for(int i = b - 1;i > a;i--)
		cout << i << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}