/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0;i < n;i++) {
		cin >> nums[i];
	}

	int g = abs(nums[0]);
	for(int i = 1;i < n;i++) {
		g = gcd(g, abs(nums[i]));
	}
	cout << g << '\n';

	return 0;
}