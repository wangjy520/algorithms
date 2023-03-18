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

void solve() {
	int n;
	cin >> n;
	unordered_set<string> ss;
	vector<string> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		ss.insert(a[i]);
	}
	string t = "";
	for(int i = 0;i < n;i++) {
		bool ok = false;
		for(int j = 0;j < a[i].size() - 1;j++) {
			if(ss.find(a[i].substr(0, j + 1)) != ss.end() && ss.find(a[i].substr(j + 1)) != ss.end()) {
				t.push_back('1');
				ok = true;
				break;
			}
		}
		if(!ok) {
			t.push_back('0');
		}
	}
	cout << t << '\n';
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