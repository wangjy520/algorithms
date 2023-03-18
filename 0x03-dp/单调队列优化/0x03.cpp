/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int inf = -2e9 + 10;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	deque<int> q;
	vector<int> pre(n + 1, 0);
	q.push_back(0);
	int res = inf;
	for(int i = 1;i <= n;i++) {
		pre[i] = pre[i - 1] + a[i - 1];
		while(!q.empty() && q.front() < i - m)
			q.pop_front();
		res = max(res, pre[i] - pre[q.front()]);
		while(!q.empty() && pre[q.back()] > pre[i])
			q.pop_back();
		q.push_back(i);
	}
	cout << res << '\n';
	return 0;
}