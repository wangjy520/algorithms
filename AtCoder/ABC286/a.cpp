/* 
** Created by Wangjy.
** Accepted
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, p, q ,r, s;
	cin >> n >> p >> q >> r >> s;
	vector<int> nums(n);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
	}
	for(int i = p - 1;i < q;i++) {
		swap(nums[i], nums[r - p + i]);
	}
	for(auto num : nums)
		cout << num << ' ';

	return 0;
}