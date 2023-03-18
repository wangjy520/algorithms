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

	int m, n;
	cin >> m >> n;
	queue<int> q;
	unordered_set<int> s;
	int res = 0;
	for(int i = 0;i < n;i++) {
		int x;
		cin >> x;
		if(s.find(x) == s.end()) {
			if(q.size() < m) {
				q.push_back(x);
			}
			else {
				res++;
				q.pop_front();
				q.push_back(x);
			}
			s.insert(x);
		}
		
	}
	cout << res << '\n';
	


	return 0;
}