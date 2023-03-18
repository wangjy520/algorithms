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
int n, k;
int res = 0;
void dfs(int i, int sum, int start) {
	if(i >= k) {
		res += sum == n;
		return ;
	}
	if(sum + start * (k - i) < n)
		return ;
	if(sum + k - i > n)
		return ;
	for(int num = start;num >= 1;num--) {
		dfs(i + 1, sum + num, num);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	
	cin >> n >> k;
	dfs(0, 0, n);
	cout << res << '\n';

	return 0;
}