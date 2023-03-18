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
int n, m;
int res = 0;
vector<bool> choose(12, false);
void dfs(vector<unordered_set<int>>& nums, int i) {
	int len = nums.size();
	if(i >= len) {
		vector<bool> v(n + 1, false);
		for(int i = 0;i < m;i++) {
			if(choose[i]) {
				for(auto& num : nums[i]) {
					v[num] = true;
				}
			}
		}
		for(int i = 1;i <= n;i++) {
			if(!v[i])
				return ;
		}
		res++;
		return ;
	}
	dfs(nums, i + 1);
	choose[i] = true;
	dfs(nums,i + 1);
	choose[i] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	
	cin >> n >> m;
	vector<unordered_set<int>> nums(m);
	for(int i = 0;i < m;i++) {
		unordered_set<int> s;
		int t;
		cin >> t;
		while(t--) {
			int a;
			cin >> a;
			s.insert(a);
		}
		nums[i] = s;
	}	
	dfs(nums, 0);
	cout << res << '\n';

	return 0;
}