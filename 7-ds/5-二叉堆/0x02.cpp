/* 
** Created by Wangjy.
** https://www.luogu.com.cn/problem/P2085
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

typedef struct Func {
	int a, b, c;
	int mn;
	Func(int aa, int bb, int cc, int mm) : a(aa), b(bb), c(cc), mn(mm) {}
}Func;

int n, m;
const int maxn = 1e4 + 10;
int nums[maxn];
int s = 1;

void push(int x) {
	nums[s++] = x;
	int cur = s - 1;
	int p = cur / 2;
	while(p >= 1) {
		if(nums[cur] < nums[p]) {
			swap(nums[cur], nums[p]);
			cur = p;
			p = cur / 2;
		}
		else {
			break;
		}
	}
}

int top() {
	return nums[1];
}

void pop() {
	s--;
	swap(nums[1], nums[s]);
	int cur = 1;
	int child = 0;
	while(cur * 2 < s) {
		child = cur * 2;
		if(child + 1 < s && nums[child] > nums[child + 1]) {
			child++;
		}
		if(nums[cur] > nums[child]) {
			swap(nums[cur], nums[child]);
			cur = child;
		}
		else {
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<Func> nums(n);
	for(int i = 0;i < n;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int mn = 
		nums[i] = new Func(a, b, c, mn);
	}
	sort(nums.begin(), nums.end(), [&](Func& o, Func& b) {return })


	return 0;
}