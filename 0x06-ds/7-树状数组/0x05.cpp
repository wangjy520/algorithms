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

const int maxn =  1e5 + 10;
LL c[maxn];
int n;

int lowbit(int x) {
	return x & (-x);
}

void add(int i, int v) {
	for(;i <= n;i += lowbit(i)) {
		c[i] += v;
	}
}

LL sum(int i) {
	LL res = 0;
	for(;i > 0;i -= lowbit(i)) {
		res += c[i];
	}
	return res;
}

LL sum(int i, int j) {
	return sum(j) - sum(i - 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> n >> m;
	for(int i = 0;i < m;i++) {
		char t;
		int a, b;
		cin >> t >> a >> b;
		if(t == 'x') {
			add(a, b);
		}
		else {
			cout << sum(b) - sum(a - 1) << '\n';
		}
	}
	


	return 0;
}