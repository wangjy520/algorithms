/* 
** Created by Wangjy.
** AC
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
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	ListNode* head = new ListNode(1);
	ListNode* pre = head;
	int i = 2;
	ListNode* node = nullptr;
	while(i <= n) {
		node = new ListNode(i);
		pre->next = node;
		pre = node;
		i++;
	}
	pre->next = head;

	for(int i = 1;i <= n;i++) {
		int cnt = 0;
		ListNode* p = pre->next;
		if(p->next == p) {
			cout << p->val << '\n';
			return 0;
		}
		while(cnt < m - 1) {
			p = p->next;
			cnt++;
			pre = pre->next;
		}
		cout << p->val << ' ';
		pre->next = p->next;

	}


	return 0;
}