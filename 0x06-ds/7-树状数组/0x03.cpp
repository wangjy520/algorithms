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

const int maxn = 5e5 + 10;
int c[maxn];
int n;

int lowbit(int x) {
	return x & (-x);
}

void init(int i, int v) {
	c[i] = v;
	for(int j = i - lowbit(i);j > 0;j -= lowbit(j)) {
		c[i] -= c[j];
	}
}

void add(int i, int k) {
	for(;i <= n;i += lowbit(i)) {
		c[i] += k;
	}
}

int sum(int i) {
	int res = 0;
	for(;i > 0;i -= lowbit(i)) {
		res += c[i];
	}
	return res;
}

int sum(int i, int j) {
	return sum(j) - sum(i - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> n >> m;
	vector<int> nums(n + 1);
	for(int i = 1;i <= n;i++) {
		cin >> nums[i];
		add(i, nums[i]);
		if(i < n)
			add(i + 1, -nums[i]);
	}
	
	for(int i = 0;i < m;i++) {
		int t;
		cin >> t;
		if(t == 1) {
			int x, y, k;
			cin >> x >> y >> k;
			add(x, k);
			if(y < n) {
				add(y + 1, -k);
			}
		}
		else {
			int x;
			cin >> x;
			cout << sum(x) << '\n';
		}
	}
	


	return 0;
}