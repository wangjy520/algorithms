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

const int maxn = 5e4 + 10;
int sum[maxn << 2];
int lsum[maxn << 2];
int rsum[maxn << 2];
int seg[maxn << 2];
int n;
vector<int> nums(maxn);

void push_up(int k) {
	sum[k] = sum[ls] + sum[rs];
	lsum[k] = max(lsum[ls], sum[ls] + lsum[rs]);
	rsum[k] = max(rsum[rs], sum[rs] + rsum[ls]);
	seg[k] = max(max(seg[ls], seg[rs]), lsum[rs] + rsum[ls]);
}

void build(int k, int s, int t) {
	if(s == t) {
		seg[k] = nums[s];
		sum[k] = nums[s];
		lsum[k] = nums[s];
		rsum[k] = nums[s];
		
		return ;
	}
	int mid = s + ((t - s) >> 1);
	build(ls, s, mid);

	build(rs, mid + 1, t);
	
	push_up(k);
}

void update(int k, int s, int t, int i, int v) {
	if(s == t) {
		if(s == i) {
			seg[k] = v;
			sum[k] = v;
			lsum[k] = v;
			rsum[k] = v;
		}
		return ;
	}
	int mid = s + ((t - s) >> 1);
	if(i <= mid) {
		update(ls, s, mid, i, v);
	}
	else {
		update(rs, mid + 1, t, i, v);
	}
	push_up(k);
}

int query(int k, int s, int t, int l, int r) {
	if(s >= l && t <= r) {
		return seg[k];
	}
	int mid = s + ((t - s) >> 1);
	int res = INT_MIN;
	if(l <= mid) {
		int lmax = query(ls, s, mid, l, r);
		res = max(lmax, res);
	}
	if(r > mid) {
	    int rmax = query(rs, mid + 1, t, l, r);
	    res = max(res, rmax);
	}
	res = max(res, lsum[rs] + rsum[ls]);

	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> nums[i];
	}
	build(1, 1, n);
	cin >> m;
	for(int i = 0;i < m;i++) {
		int t;
		cin >> t;
		if(t == 1) {
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << '\n';
		}
		else {
			int x, y;
			cin >> x >> y;
			update(1, 1, n, x, y);
		}
	}
	


	return 0;
}