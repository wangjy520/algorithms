/* 
** Created by Wangjy.
** https://www.luogu.com.cn/problem/P1843
** Accepted
** 二分答案
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int n, a, b;
const int maxn = 5e5 + 10;
vector<int> nums(maxn, 0);

bool check(int mid) {
	int s = 0;
	for(int i = 0;i < n;i++) {
		if((nums[i] + a - 1) / a > mid)
			s += (nums[i] - a * mid + b - 1) / b;
	}
	return mid >= s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> a >> b;
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
	}

	int l = 0, r = maxn;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l << '\n';


	return 0;
}