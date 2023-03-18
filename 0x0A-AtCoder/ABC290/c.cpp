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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	unordered_set<int> s;
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
		s.insert(nums[i]);
	}
	int cnt = 0;
	int i = 0;
	while(cnt < k) {
		if(s.find(i) != s.end()) {
			i++;
		}
		else {
			cout << i << '\n';
			return 0;
		}

		cnt++;
	}
	cout << i << '\n';



	return 0;
}