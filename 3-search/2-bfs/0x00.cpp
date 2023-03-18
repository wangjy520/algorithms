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

int dirs[12][2] = {{-2, -2}, {2, 2}, {2, -2}, {-2, 2}, {1, 2}, {-1, -2}, {1, -2}, {-1, 2}, {2, 1}, {-2, -1}, {2, -1}, {-2, 1}};

int solve(int x, int y) {
	int n = 50;
	vector<vector<int>> v(n, vector<int>(n, -1));
	v[1][1] = 0;
	queue<pii> q;
	q.push({1, 1});
	while(!q.empty()) {
		pii node = q.front();
		q.pop();
		int i = node.first;
		int j = node.second;
		for(auto& d :dirs) {
			int row = i + d[0], col = j + d[1];
			if(row >= 1 && col >= 1 && row < n && col < n) {
				if(v[row][col] == -1 && v[row][col] < v[i][j] + 1) {
					v[row][col] = v[i][j] + 1;
					q.push({row, col});
				}
			}
		}
	}
	return v[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << solve(x1, y1) << '\n';
	cout << solve(x2, y2) << '\n';
	


	return 0;
}