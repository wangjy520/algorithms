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

	string s;
	cin >> s;
	int n = s.size();
	stack<char> st;
	for(int i = 0;i < n - 1;i++) {
		if(s[i] == '(') {
			st.push(s[i]);
		}
		else if(s[i] == ')') {
			if(st.empty()) {
				cout << "NO" << '\n';
				return 0;
			}
			else {
				st.pop();
			}
		}
	}
	cout << (st.empty() ? "YES" : "NO") << '\n';
	


	return 0;
}