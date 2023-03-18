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


int n, m;
const int maxn = 20010;
int par[maxn << 1];
int r[maxn << 1];

void init() {
	for(int i = 0;i < maxn;i++) {
		par[i] = i;
		par[i + maxn] = i + maxn;
		r[i] = 0;
		r[i + maxn] = 0;
	}
}

int find(int x) {
	return x == par[x] ? x : (par[x] = find(par[x]));
}

void merge(int s, int t) {
	int x = find(s), y = find(t);
	if(r[x] < r[y])
		par[x] = y;
	else 
		par[y] = x;
	if(x != y && r[x] == r[y])
		r[x]++;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<int>> nums(m, vector<int>(3));
	for(int i = 0;i < m;i++) {
		cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
	}
	init();
	sort(nums.begin(), nums.end(), [&](vector<int>& a, vector<int>& b) {return a[2] > b[2];});
	for(auto& v : nums) {
		if(find(v[0]) == find(v[1]) || find(v[0] + maxn) == find(v[1] + maxn)) {
			cout << v[2] << '\n';
			return 0;
		}
		merge(v[0], v[1] + maxn);
		merge(v[1], v[0] + maxn);
	}	
	cout << 0 << '\n';


	return 0;
}