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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> nums(n + 1);
	for(int i = 1;i <= n;i++) {
		cin >> nums[i];
	}
	int t = log(n) / log(2) + 1;

	vector<vector<int>> f(n + 1, vector<int>(t, 0)), g(n + 1, vector<int>(t, 0x3f3f3f3f));
	for(int i = 1;i <= n;i++) {
		f[i][0] = nums[i];
		g[i][0] = nums[i];
	}
	for(int j = 1;j < t;j++) {
		for(int i = 1;i <= (n + 1 - (1 << j));i++) {
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
			g[i][j] = min(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
		}
	}
	for(int i = 0;i < q;i++) {
		int l, r;
		cin >> l >> r;
		int len = log(r - l + 1) / log(2);
		cout << max(f[l][len], f[r - (1 << len) + 1][len]) - min(g[l][len], g[r - (1 << len) + 1][len]) << '\n';
	}
	


	return 0;
}