/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct DSU
{
	vector<int> p, s;
	DSU(int n) : p(n), s(n, 1) {iota(p.begin(), p.end(), 0);}
	int find(int x) {
		return x == p[x] ? x : (p[x] = find(p[x]));
	}
	bool same(int x, int y) {return find(x) == find(y);}
	void merge(int x, int y) {
		x = find(x);
		y = find(y);
		if(s[x] < s[y]) {
			p[x] = y;
			s[y] += s[x];
		}
		else {
			p[y] = x;
			s[x] += s[y];
		}
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	DSU dsu(n + 1);

	for(int i = 0;i < k;i++) {
		int a, b;
		cin >> a >> b;
		dsu.merge(a, b);
	}
	vector<int> nums;
	for(int i = 1;i <= n;i++) {
		if(i == dsu.find(i)) {
			nums.push_back(dsu.s[i]);
		}
	}
	sort(nums.begin(), nums.end());
	int index = lower_bound(nums.begin(), nums.end(), m) - nums.begin();
	if(index > 0 && abs(nums[index - 1] - m) <= abs(nums[index] - m)) {
		cout << nums[index - 1] << '\n';
	}
	else {
		cout << nums[index] << '\n';
	}


	

	return 0;
}