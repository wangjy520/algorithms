/* 
** Created by Wangjy.
** 考虑什么情况下k的函数值才是最大的
** 只有当k既是左端点又是右端点的情况下，才有可能是最大的
** 这个思路确实想不到啊。。。
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
	int n, k;
	cin >> n >> k;
	bool fs1 = false, fs2 = false;
	for(int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		if(a == k)
			fs1 = true;
		if(b == k)
			fs2 = true;
	}
	cout << ((fs1 && fs2) ? "YES" : "NO") << '\n';
	

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