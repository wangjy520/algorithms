#include<bits/stdc++.h>

using namespace std;

const int maxn = 110;
int parent[maxn];
int r[maxn];

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


int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0;i < maxn;i++) {
		parent[i] = i;
		r[i] = 0;
	}
	for(int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	unordered_set<int> ss;
	for(int i = 1;i <= n;i++) {
		ss.insert(find(i));
	}
	cout << ss.size() << '\n';

	return 0;
} 
    
    
