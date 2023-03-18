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

const LL maxn = 21;
const LL inf = 0x3f3f3f3f3f3f3f3f;
vector<vector<vector<LL>>> f(maxn, vector<vector<LL>>(maxn, vector<LL>(maxn, inf)));

LL solve(LL a, LL b, LL c) {
	if(a >= 0 && b >= 0 && c >= 0 && a <= 20 && b <= 20 && c <= 20) {
		if(f[a][b][c] != inf) {
			return f[a][b][c];
		}
	}
	LL res = inf;
	if(a <= 0 || b <= 0 || c <= 0) {
		res = 1;
	}
	else if(a > 20 || b > 20 || c > 20) {
		res =  solve(20, 20, 20);
	}
	else if(a < b && b < c) {
		res = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
	}
	else {
		res = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
	}

	if(a >= 0 && b >= 0 && c >= 0 && a <= 20 && b <= 20 && c <= 20) {
		if(f[a][b][c] == inf) {
			f[a][b][c] = res;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	LL a, b, c;
	cin >> a >> b >> c;
	while(a != - 1 || b != -1 || c != -1) {
		LL res = solve(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << res << '\n';
		cin >> a >> b >> c;
	}

	return 0;
}