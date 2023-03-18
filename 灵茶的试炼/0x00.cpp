/* 
** Created by Wangjy.
** 1 2
** 2 3
** 3 3
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int maxn = 1e5 + 10;
vector<vector<int>> edges(maxn, vector<int>());
vector<bool> v(maxn, false);
bool is_tree = true;
int s = 0, e = 0;
void dfs(int i) {
	v[i] = true;
	s++;
	for(auto& child : edges[i]) {
		if(!v[child]) {
			dfs(child);
		}
		e++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	unordered_set<int> ss;
	for(int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		ss.insert(a);
		ss.insert(b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	int res = 0;
	for(int i = 1;i < maxn;i++) {
		if(!v[i] && ss.find(i) != ss.end()) {
			s = 0;
			is_tree = true;
			dfs(i);
			if(e == s - 1)
				res += (s - 1);
			else 
				res += s;
		}
	}
	cout << res << '\n';
	

	

	return 0;
}