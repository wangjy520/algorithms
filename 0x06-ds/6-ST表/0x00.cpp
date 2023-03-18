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


	int n, m;
	cin >> n >> m;
	vector<int> nums(n + 1);
	for(int i = 1;i <= n;i++) {
		cin >> nums[i];
	}
	int t = log(n) / log(2) + 1;
	vector<vector<int>> f(n + 1, vector<int>(t, 0));
	for(int i = 1;i <= n;i++) {
		f[i][0] = nums[i];
	}
	for(int j = 1;j < t;j++) {
		for(int i = 1;i <= (n - (1 << j) + 1);i++) {
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
	for(int i = 0;i < m;i++) {
		int l, r;
		cin >> l >> r;
		int len = log(r - l + 1) / log(2);
		cout << max(f[l][len], f[r - (1 << len) + 1][len]) << '\n';
	}

	return 0;
}