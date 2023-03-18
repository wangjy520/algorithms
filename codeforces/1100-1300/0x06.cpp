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
	vector<int> a(n);
	for(auto& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());
	int q;
	cin >> q;
	for(int i = 0; i < q;i++) {
		int x;
		cin >> x;
		int id = upper_bound(a.begin(), a.end(), x) - a.begin();
		cout << id << '\n';
	}

	return 0;
}