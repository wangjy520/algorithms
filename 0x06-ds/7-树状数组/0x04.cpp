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

const int maxn = 1e5 + 10;
int c[maxn];
int n;

int lowbit(int x) {
	return x & (-x);
}

void add(int i, int v) {
	for(;i <= n;i += lowbit(i)) {
		c[i] += v;
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
	for(int i = 0;i < m;i++) {
		int t;
		cin >> t;
		if(t == 1) {
			int l, r;
			cin >> l >> r;
			add(l, 1);
			if(r < n) {
				add(r + 1, -1);
			}
		}
		else {
			int x;
			cin >> x;
			cout << sum(x) % 2 << '\n';
		}
	}


	return 0;
}