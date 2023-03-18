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
	stack<int> st;
	int i = 0;
	int num = 0;
	while(i < n - 1) {
		if(s[i] >= '0' && s[i] <= '9') {
			num = num * 10 + (s[i] - '0');
		}
		else if(s[i] == '.'){
			st.push(num);
			num = 0;
			
		}
		else {
			int num1 = st.top();
			st.pop();
			int num2 = st.top();
			st.pop();
			if(s[i] == '+') {
				st.push(num1 + num2);
			}
			else if(s[i] == '-') {
				st.push(num2 - num1);
			}
			else if(s[i] == '*'){
				st.push(num1 * num2);
			}
			else if(s[i] == '/') {
				st.push(num2 / num1);
			}
		}
		i++;
	}
	cout << st.top() << '\n';
	


	return 0;
}