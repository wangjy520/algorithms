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
typedef struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int v) : val(v), next(nullptr) {}
	ListNode(int v, ListNode* _next) : val(v), next(_next) {}
}ListNode;

const int maxn = 4e5 + 10;
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
	if(r[x] < r[y]) {
		parent[x] = y;
	}
	else {
		parent[y] = x;
	}
	if(x != y && r[x] == r[y])
		r[x]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n, m;
	cin >> n >> m;
	init();
	vector<vector<int>> edges(maxn, vector<int>());
	unordered_set<int> s;
	for(int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	int k;
	cin >> k;
	vector<int> hit(k);
	for(int i = 0;i < k;i++) {
		cin >> hit[i];
		s.insert(hit[i]);
	}
	vector<int> res;
	for(int i = 0;i < n;i++) {
		if(s.find(i) != s.end())
			continue;
		vector<int> v = edges[i];
		for(auto j : v) {
			if(s.find(j) != s.end())
				continue;
			merge(i, j);
		}
	}
	unordered_set<int> cnt;
	for(int i = 0;i < n;i++) {
		if(s.find(i) == s.end())
			cnt.insert(find(i));
	}
	res.push_back(cnt.size());
	int sum = cnt.size();
	for(int i = k - 1;i >= 0;i--) {
		sum++;
		s.erase(hit[i]);
		for(int j : edges[hit[i]]) {
			if(s.find(j) != s.end())
				continue;
			if(find(hit[i]) != find(j)) {
				sum--;
				merge(hit[i], j);
			}
			
		}
		res.push_back(sum);
	}
	for(int i = res.size() - 1;i >= 0;i--) {
		cout << res[i] << '\n';
	}




	return 0;
}