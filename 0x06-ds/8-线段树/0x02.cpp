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
const int maxn = 2e5 + 10;
int n, m;
vector<LL> seg(maxn * 4, 0);
vector<LL> tag(maxn * 4, 0);

void push_down(int k, int s, int t) {
	if(tag[k]) {
		int mid = s + ((t - s) >> 1);
		seg[k << 1] += tag[k] * (mid - s + 1);
		seg[k << 1 | 1] += tag[k] * (t - mid);
		tag[k << 1] += tag[k];
		tag[k << 1 | 1] += tag[k];
		tag[k] = 0;
	}
}

void push_up(int k) {
	seg[k] = seg[k << 1] + seg[k << 1 | 1];
}

void update(int k, int s, int t, int l, int r, int v) {
	if(s >= l && t <= r) {
		tag[k] += v;
		seg[k] += v * (t - s + 1);
	}
	push_down(k, s, t);
	int mid = s + ((t - s) >> 1);
	if(l <= mid) {
		update(k << 1, s, mid, l, r, v);
	}
	// if(r > mid) {
	// 	update(k << 1 | 1, mid + 1, t, l, r, v);
	// }
	push_up(k);
}


long long query(int k, int s, int t, int l, int r) {
	if(s >= l && t <= r) {
		return seg[k];
	}
	push_down(k, s, t);
	int mid = s + ((t - s) >> 1);
	long long res = 0;
	if(l <= mid)
		res += query(k << 1, s, mid, l, r);
	if(r > mid)
		res += query(k << 1 | 1, mid + 1, t, l, r);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		int a;
		cin >> a;
		update(1, 1, n, i, i, a);
	}
	for(int i = 0;i < m;i++) {
		int op;
		cin >> op;
		if(op == 1) {
			int l, r, k;
			cin >> l >> r >> k;
			update(1, 1, n, l, r, k);
		}
		else if(op == 2) {
			int k;
			cin >> k;
			update(1, 1, n, 1, 1, k);
		}
		else if(op == 3) {
			int k;
			cin >> k;
			update(1, 1, n, 1, 1, -k);
		}
		else if(op == 4) {
			int l, r;
			cin >> l >> r;
			
			cout << query(1, 1, n, l, r) << '\n';
		}
		else {
			cout << query(1, 1, n, 1, 1) << '\n';
		}
	}

	return 0;
}