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
	string s;
	int n;
	cin >> s >> n;
	int h = stoi(s.substr(0, 2));
	int m = stoi(s.substr(3));
	int sum = h * 60 + m;
	int cur = sum;
	int res = 0;
	while(cur < sum + 24 * 60) {
		int c = cur % (24 * 60);
		string t1 = to_string(c % 60);
		if(t1.size() == 1)
			t1 = "0" + t1;
		string t2 = to_string(c / 60);
		if(t2.size() == 1)
			t2 = "0" + t2;
		
		string t = t2 + t1;
		if(n == 27)
			cout << t << '\n';
		if(t[0] == t[3] && t[1] == t[2]) {
			res++;
		}
		cur += n;
	}
	cout << res << '\n';
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