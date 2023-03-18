/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int maxn = 2e6 + 10;

int parent[maxn];
int r[maxn];

void init() {
	for(int i = 0;i < maxn;i++) {
		parent[i] = i;
		r[i] = 0;
	}
}

int find(int x) {
	return x == parent[x] ? x : (parent[x] = find(parent[x]));
}

void merge(int s, int t) {
	int x = find(s), y = find(t);
	if(r[x] < r[y])
		parent[x] = y;
	else 
		parent[y] = x;
	if(x != y && r[x] == r[y])
		r[x]++;
}


void solve() {
	init();
	int n;
	cin >> n;
	vector<pii> v;
	unordered_map<int, int> m;
	int cnt = 1;
	for(int i = 0;i < n;i++) {
		int a, b, x;
		cin >> a >> b >> x;
		if(m.find(a) == m.end()) {
			m[a] = cnt++;
		}
		if(m.find(b) == m.end()) {
			m[b] = cnt++;
		}
		if(x == 0) {

			v.push_back(make_pair(m[a], m[b]));
		}
		else {
			merge(m[a], m[b]);
		}
	}
	for(auto& p : v) {
		if(find(p.first) == find(p.second)) {
			cout << "NO" << '\n';
			return ;
		}
	}
	cout << "YES" << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	


	return 0;
}