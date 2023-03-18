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
const int inf = 0x3f3f3f3f;
const int maxn = 5;
vector<int> nums((maxn * maxn));
vector<vector<int>> v(maxn, vector<int>(maxn, inf));
vector<bool> visited((maxn * maxn), false);
int n;

bool check(int x, bool is_row, int sum) {
	if(is_row) {
		int s = 0;
		for(int j = 0;j < n;j++) {
			s += v[x][j];
		}
		return s == sum;
	}
	else {
		int s = 0;
		for(int i = 0;i < n;i++) {
			s += v[i][x];
		}
		return s == sum;
	}
}

bool check(int x, int y, bool m, int sum) {
	int s = 0;
	if(m) {
		while(x >= 0 && y >= 0) {
			s += v[x--][y--];
		}
	}
	else {
		while(x >= 0 && y < n) {
			s += v[x--][y++];
		}
	}
	return s == sum;
}

void print(int sum) {
	cout << sum << '\n';
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
}

void dfs(int i, int j, int sum) {
	if(i >= n) {
		// cout << "here" << '\n';
		print(sum);
		return;
	}
	cout << i << " " << j << '\n';
	for(int k = 0;k < n * n;k++) {
		if(!visited[k]) {
			visited[k] = true;
			v[i][j] = nums[k];
			if(j == n - 1 && !check(i, true, sum)) {
				// visited[k] = false;
				continue;
			}
			if(i == n - 1 && !check(j, false, sum)) {
				// visited[k] = false;
				continue ;
			}
			if(i == n - 1 && j == 0 && !check(i, j, false, sum)) {
				// visited[k] = false;
				continue ;
			}
			if(i == n - 1 && j == n - 1 && !check(i, j, true, sum)) {
				// visited[k] = false;
				continue ;
			}
			if(j == n - 1) {
				// cout << "here" << '\n';
				dfs(i + 1, 0, sum);
			}
			else {
				dfs(i, j + 1, sum);
			}
			visited[k] = false;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	
	cin >> n;
	
	int sum = 0;
	for(int i = 0;i < n * n;i++) {
		cin >> nums[i];
		sum += nums[i];
	}
	sum /= n;
	sort(nums.begin(), nums.begin() + n * n, less<int>());
	dfs(0, 0, sum);
	// print(sum);
	


	return 0;
}