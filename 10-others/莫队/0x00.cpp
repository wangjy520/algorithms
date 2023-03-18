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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1, 0);
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	int len = (int) sqrt(n);
	int s = (n + len - 1) / len;
	vector<pii> q(m);
	for(int i = 0;i < m;i++) {
		int l, r;
		cin >> l >> r;
		q[i] = make_pair(l ,r);
	}
	// vector<int> id(m);
	// iota(id.begin(), id.end(), 0);
	vector<vector<int>> nums(s, vector<int>());
	for(int i = 0;i < m;i++) {
		auto p = q[i];
		int j = p.first / len;
		nums[j].push_back(i);
	}

	for(int i = 0;i < s;i++) {
		sort(nums[i].begin(), nums[i].end(), [&](int o, int p) {return q[o].second < q[p].second;});
	}
	vector<bool> res(m);
	for(int i = 0;i < s;i++) {
		if(nums[i].size() == 0)
			continue;
		int index = 0;
		vector<int> cnt((int)1e5 + 10, 0);
		int l = 1, r = 1;
		int k = 1;
		for(int j = 0;j < nums[i].size();j++) {
			index = nums[i][j];
			// cout << l << " " << r << " " << q[index].first << " " << q[index].second << '\n';
			k = r;
			while(k <= q[index].second) {
				cnt[a[k]]++;
				k++;
			}
			r = k;
			k = l;
			if(k < q[index].first) {
				while(k < q[index].first) {
					cnt[a[k]]--;
					k++;
				}
				l = k;
			}
			else {
				while(k >= q[index].first) {
					cnt[a[k]]++;
					k--;
				}
				l = k + 1;
			}
			bool fs = false;
			for(int k = l;k <= r;k++) {
				if(cnt[a[k]] > 1) {
					fs = true;
					res[index] = false;
					break;
				}
			}
			if(!fs) {
				res[index] = true;
			}
		}
	}
	// for(int i = 0;i < s;i++) {
	// 	for(auto& j : nums)
	// }
	for(int i = 0;i < res.size();i++) {
		bool fs = res[i];
		if(fs)
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}
	return 0;
}