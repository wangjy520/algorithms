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
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

const int maxn = 110;
vector<vector<int>> nums(maxn, vector<int>(maxn)), v(maxn, vector<int>(maxn, -1));
int n, m;

int dfs(int i, int j) {
	if(v[i][j] != -1) {
		return v[i][j];
	}
	int res = 1;
	for(auto& d : dirs) {
		int row = i + d[0], col = j + d[1];
		if(row >= 0 && row < n && col >= 0 && col < m) {
			if(nums[row][col] < nums[i][j]) {
				res = max(res, 1 + dfs(row, col));
			}
		}
	}
	if(v[i][j] == -1)
		v[i][j] = res;
	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	
	cin >> n >> m;
	
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			cin >> nums[i][j];
		}
	}
	int res = 0;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			res = max(res, dfs(i, j)); 
		}
	}
	cout << res << '\n';


	return 0;
}