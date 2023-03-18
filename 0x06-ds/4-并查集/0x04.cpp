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
int n;
const int maxn = 3e4 + 10;

int parent[maxn];
int d[maxn];
int s[maxn];

void init() {
	for(int i = 0;i < maxn;i++) {
		parent[i] = i;
		d[i] = 0;
		s[i] = 1;
	}
}

int find(int x) {
	if(x == parent[x])
		return x;
	int p = find(parent[x]);
	d[x] += d[parent[x]];
	return parent[x] = p;
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	parent[x] = y;
	d[x] = s[y];
	s[y] += s[x];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	init();
	for(int i = 0;i < n;i++) {
		int a, b;
		char t;
		cin >> t >> a >> b;
		if(t == 'M') {
			merge(a, b);
		}
		else {
			if(find(a) == find(b)) {
				cout << abs(d[a] - d[b]) - 1 << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
	}
	


	return 0;
}