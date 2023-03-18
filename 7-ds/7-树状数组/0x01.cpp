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
	return  x & (-x);
}

void add(int i, int v) {
	for(;i <= n;i += lowbit(i))
		c[i] += v;
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

	cin >> n;
	for(int i = 0;i < maxn;i++)
		c[i] = 0;
	vector<int> nums(n + 1), arr(n + 1);
	for(int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		nums[i] = x;
		arr[i] = x;
	}
	sort(arr.begin(), arr.end(), less<int>());
	
	unordered_map<int, int> m;
	m[arr[1]] = 1;
	int pre = arr[1];
	for(int i = 2;i <= n;i++) {
		if(arr[i] == arr[i - 1]) {
			m[arr[i]] = m[arr[i - 1]];
		}
		else {
			m[arr[i]] = m[arr[i - 1]] + 1;
		}
	}
	
	LL res = 0;
	for(int i = 1;i <= n;i++) {
		res += sum(m[nums[i]] + 1, maxn - 1);
		add(m[nums[i]], 1);
	}
	cout << res << '\n';
	
	


	return 0;
}