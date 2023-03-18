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



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int res = 0;
	for(int i = 0;i < n;i++) {
		int a;
		cin >> a;
		res ^= a;
	}
	cout << res << '\n';
	


	return 0;
}