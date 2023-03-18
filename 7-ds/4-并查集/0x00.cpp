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

const int maxn = 1010;
int parent[maxn];
int r[maxn];
int sum;

void init(int n) {
	for(int i = 1;i <= n;i++) {
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
	sum = n;
	init(n);
	vector<vector<int>> nums(m);
	for(int i = 0;i < m;i++) {
		int a, b, t;
		cin >> a >> b >> t;
		vector<int> v(3);
		v[0] = a;
		v[1] = b;
		v[2] = t;
		nums[i] = v;
	}
	sort(nums.begin(), nums.end(), [&](vector<int>& a, vector<int>& b) {return a[2] < b[2];});
	if(sum == 1) {
		cout << 0 << '\n';
		return 0;
	}
	for(auto& v : nums) {
		if(find(v[0]) != find(v[1])) {
			merge(v[0], v[1]);
			sum--;
		}
		if(sum == 1) {
			cout << v[2] << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';

	


	return 0;
}