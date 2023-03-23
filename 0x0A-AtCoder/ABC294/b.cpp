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

	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0;i < n;i++) {
		string s = "";
		for(int j = 0;j < m;j++) {
			if(a[i][j] == 0)
				s += '.';
			else 
				s += a[i][j] + 'A' - 1;
		}
		cout << s << '\n';
	}

	return 0;
}