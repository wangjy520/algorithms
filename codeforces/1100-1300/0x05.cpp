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

	int n, m, a, b;
	cin >> n >> m >> a >> b;
	if(b <= m * a) {
		cout << min((b * ((n + m - 1) / m)), (b * (n / m) + a * (n % m))) << '\n';
	}
	else {
		cout << n * a << '\n';
	}

	return 0;
}