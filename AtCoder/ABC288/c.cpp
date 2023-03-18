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

const int maxn = 2e5 + 10;
vector<vector<int>> edges(maxn, vector<int>());
vector<bool> v(maxn, false);
int n, m;
int res = 0;

void dfs(int i, int par) {
	v[i] = true;
	for(auto& child : edges[i]) {
		if(child == par) {
			continue;
		}
		if(v[child]) {
			res++;
		}
		else {
			dfs(child, i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int i = 1;i <= n;i++) {
		if(!v[i]) {
			dfs(i, -1);
		}
	}
	cout << (res / 2) << '\n';


	return 0;
}