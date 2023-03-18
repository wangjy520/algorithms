/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

#define ls (k << 1)
#define rs ((k << 1) | 1)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int maxn = 2e5 + 10;
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

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if(r[x] < r[y])
		parent[x] = y;
	else 
		parent[y] = x;
	if(x != y && r[x] == r[y])
		r[x]++;
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	if(n != m + 1) {
		cout << "No" << '\n';
		return 0;
	}
	if(n == 1) {
		cout << "Yes" << '\n';
	}
	init();
	vector<int> d(n + 1, 0);
	for(int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		d[a]++;
		d[b]++;
		merge(a, b);
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++) {
		if(d[i] == 1) {
			cnt++;
		}
		else if(d[i] > 2 || d[i] == 0) {
			cout << "No" << '\n';
		}
	}
	bool ok = false;
	unordered_set<int> ss;
	for(int i = 1;i <= n;i++) {
		ss.insert(find(i));
	}
	cout << (cnt == 2 && ss.size() == 1 ? "Yes" : "No") << '\n';
	


	return 0;
}