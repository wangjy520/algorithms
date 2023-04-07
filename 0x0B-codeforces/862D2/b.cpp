/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	char mn = *min_element(s.begin(), s.end());
	for(int i = n - 1;i >= 0;i--) {
		if(s[i] == mn) {
			cout << mn;
			string t = "";
			t += s.substr(0, i) + s.substr(i + 1);
			cout << t << '\n';
			return ;
		}
	}
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