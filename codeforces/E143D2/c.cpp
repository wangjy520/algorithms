/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;


void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	// 前缀和，前i个人一共需要喝多少茶
	vector<LL> pre(n + 1, 0L);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for(int i = 0;i < n;i++) {
		cin >> b[i];
		pre[i + 1] = pre[i] + b[i];
	}
	// 每个人喝了多少次完整的茶（喝了b[i]）
	vector<int> cnt(n, 0);
	// 每个和喝了多少不完整的茶，最后相加就是喝的茶的总数
	vector<LL> s(n, 0L);
	for(int i = 0;i < n;i++) {
		// 二分查找第i种茶能够被最多连续多少人喝掉
		int id = lower_bound(pre.begin(), pre.end(), pre[i] + a[i]) - pre.begin();
		// 后面的全部人都能喝到完整的茶
		if(id == n + 1) {
			cnt[i]++;
		}
		// 只能让第i个人喝茶
		else if(id == i + 1) {
			s[i] += a[i];
		}
		else {
			cnt[i]++;
			if(id < n) {
				cnt[id]--;
			}
			if(pre[id] - pre[i] > a[i] && id < n) {
				s[id] += a[i] - (pre[id - 1] - pre[i]);
			}
		}
		
	}
	vector<LL> res(n, 0L);
	// cout << (long long) b[0] * cnt[0] + s[0] << " ";
	for(int i = 0;i < n;i++) {
		cout << cnt[i] << " ";
	}
	for(int i = 1;i < n;i++) {
		cnt[i] += cnt[i - 1];
		res[i] = (long long) b[i] * cnt[i] + s[i];
		// cout << res[i] << ' ';
	}
	cout << '\n';
	for(int i = 0;i < n;i++) {
		cout << cnt[i] << " ";
	}
	cout << '\n';
	for(int i = 0;i < n;i++) {
		cout << s[i] << " ";
	}
	

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}