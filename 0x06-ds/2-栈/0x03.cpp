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

const int mod = 1e4;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	stack<int> st;
	stack<char> op;
	int n = s.size();
	int i = 0;
	int num = 0;
	while(i < n) {
		if(s[i] >= '0' && s[i] <= '9') {
			num = num * 10 + (s[i] - '0');
			if(i == n - 1 || s[i + 1] < '0' || s[i + 1] > '9') {
				num %= mod;
				st.push(num);
				num = 0;
			}
		}
		else {
			if(op.empty() || s[i] == '*' && op.top() == '+') {
				op.push(s[i]);
			}
			else {
				while(!op.empty() && !(s[i] == '*' && op.top() == '+')) {
					int num1 = st.top();
					st.pop();
					int num2 = st.top();
					st.pop();
					char ch = op.top();
					op.pop();
					if(ch == '+') {
						st.push((num1 + num2) % mod);
					}
					else {
						st.push((int) ((LL)num1 * num2) % mod);
					}
				}
				op.push(s[i]);
			}
		}
		i++;
	}
	while(!op.empty()) {
		int num1 = st.top();
		st.pop();
		int num2 = st.top();
		st.pop();
		char ch = op.top();
		op.pop();
		if(ch == '+') {
			st.push((num1 + num2) % mod);
		}
		else {
			st.push((int) ((LL)num1 * num2) % mod);
		}
	}
	cout << st.top() << '\n';
	


	return 0;
}