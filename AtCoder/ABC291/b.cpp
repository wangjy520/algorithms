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

	int n;
	cin >> n;
	vector<int> a(n * 5);
	for(int i = 0;i < n * 5;i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	double res = 0;
	for(int i = n;i < 4 * n;i++) {
		res += a[i];
	}
	cout << (res / (3 * n)) << '\n'; 

	return 0;
}