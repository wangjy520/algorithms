/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

// 我真的是不太会哇：）

void solve() {
	int n, k;
	cin >> n >> k;
	string s, t;
	cin >> s >> t;

	// 对s中的字符进行去重
	vector<char> chs;
	vector<int> id(256, -1);
	for(auto ch : s) {
		if(id[ch] == -1) {
			chs.emplace_back(ch);
			id[ch] = chs.size() - 1;
		}
	}

	int m = chs.size();
	k = min(k, m);

	LL res = 0;
	for(int i = 0;i < (1 << m);i++) {
		if(__builtin_popcount(i) != k)
			continue;
		auto ss = s;
		for(int j = 0;j < n;j++) {
			if((i >> id[ss[j]]) & 1)
				ss[j] = t[j];
		}
		LL ans = 0;
		int len = 0;
		for(int j = 0;j < n;j++) {
			if(ss[j] == t[j]) {
				len++;
			}
			else {
				ans += (long long) (len + 1) * len / 2;
				len = 0;
			}
		}
		ans += (long long) len * (len + 1) / 2;
		res = max(res, ans);
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