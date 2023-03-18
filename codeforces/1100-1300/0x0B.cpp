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
	vector<pii> a(n);
	for(int i = 0;i < n;i++) {
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}
	sort(a.begin(), a.end());
	int mx = a[0].second;
	for(int i = 1;i < n;i++) {
		if(a[i].second < mx && a[i].first > a[i - 1].first) {
			cout << "Happy Alex" << '\n';
			return 0;
		}
		else {
			mx = a[i].second;
		}
	}
	cout << "Poor Alex" << '\n';

	return 0;
}