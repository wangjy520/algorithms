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
	ListNode* next, * pre;
	ListNode() : val(), next(nullptr), pre(nullptr) {}
	ListNode(int v) : val(v), next(nullptr), pre(nullptr) {}
	ListNode(int v, ListNode* p, ListNode* pp) : val(v), next(p), pre(pp) {}
}ListNode, *List;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	List h = new ListNode();
	List pp = new ListNode(1, nullptr, h);
	h->next = pp;
	pp->pre = h;
	unordered_map<int, List> m;
	m[1] = pp;
	for(int i = 2;i <= n;i++) {
		int k, p;
		cin >> k >> p;
		List node = nullptr;
		if(p == 0) {
			node = m[k]->pre;
		}
		else {
			node = m[k];
		}
		List new_node = new ListNode(i);
		new_node->next = node->next;
		node->next->pre = new_node;
		new_node->pre = node;
		node->next = new_node;
		m[i] = new_node;
		
	}
	int mm;
	cin >> mm;
	for(int i = 0;i < mm;i++) {
		int x;
		cin >> x;
		if(m.find(x) != m.end()) {
			List pre = m[x]->pre;
			pre->next = m[x]->next;
			m[x]->next->pre = pre;
			m.erase(x);

		}
	}
	pp = h->next;
	while(pp != nullptr) {
		cout << pp->val << " ";
		pp = pp->next;
	}

	return 0;
}