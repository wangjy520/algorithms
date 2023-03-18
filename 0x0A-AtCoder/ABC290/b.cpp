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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	string s;
	cin >> n >> k >> s;
	int cnt = 0;
	for(int i = 0;i < n;i++) {
		if(s[i] == 'o') {
			if(cnt >= k) {
				s[i] = 'x';
			}
			else {
				cnt++;
			}
		}

	}
	cout << s << '\n';

	return 0;
}