/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

#define ls (k << 1)
#define rs ((k << 1) | 1)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int maxn = 1e5 + 10;
LL seg[maxn << 2];
LL tag[maxn << 2];
int n;
vector<LL> nums(maxn);

void push_up(int k) {
	seg[k] = seg[ls] + seg[rs];
}

void build(int k, int s, int t) {
	if(s == t) {
		seg[k] = nums[s];
		tag[k] = 0L;
		return ;
	}
	int mid = s + ((t - s) >> 1);
	build(ls, s, mid);
	build(rs, mid + 1, t);
	push_up(k);
}

void push_down(int k, int s, int t) {
	if(tag[k] != 0) {
		int mid = s + ((t - s) >> 1);
		seg[ls] += tag[k] * (mid - s + 1);
		tag[ls] += tag[k];
		seg[rs] += tag[k] * (t - mid);
		tag[rs] += tag[k];
		tag[k] = 0;
	}
}

void update(int k, int s, int t, int l, int r, int v) {
	if(s >= l && t <= r) {
		seg[k] += (LL) (t - s + 1) * v;
		tag[k] += (LL) v;
		return ;
	}
	push_down(k, s, t);
	int mid = s + ((t - s) >> 1);
	if(l <= mid) {
		update(ls, s, mid, l, r, v);
	}
	if(r > mid) {
		update(rs, mid + 1, t, l, r, v);
	}
	push_up(k);
}

LL query(int k, int s, int t, int l, int r) {
	if(s >= l && t <= r) {
		return seg[k];
	}
	push_down(k, s, t);
	LL res = 0;
	int mid = s + ((t - s) >> 1);
	if(l <= mid) {
		res += query(ls, s, mid, l, r);
	}
	if(r > mid) {
		res += query(rs, mid + 1, t, l, r);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> nums[i];
	}
	build(1, 1, n);
	for(int i = 0;i < m;i++) {
		int t, x, y;
		cin >> t >> x >> y;
		if(t == 1) {
			int k;
			cin >> k;
			update(1, 1, n, x, y, k);
		}
		else {
			cout << query(1, 1, n, x, y) << '\n';
		}
	}

	


	return 0;
}