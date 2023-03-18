/* 
** Created by Wangjy.
** https://codeforces.com/problemset/problem/600/C
** 自己AC，并且思路和0x3F的思路完全一样
** 就是代码调了很久才调通
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

string generate(vector<int>& cnt) {

	int c = -1;
	string s = "";
	for(int i = 0;i < 26;i++) {
		if(cnt[i] % 2 == 1) {
			c = i;
		}
		for(int j = 0;j < cnt[i] / 2;j++) {
			s += (char)('a' + i);
		}
	}
	string t(s);
	reverse(t.begin(), t.end());
	
	if(c != -1) {
		return s + (char) (c +'a') + t;
	}
	else {
		return s + t;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	vector<int> cnt(26, 0);
	for(int i = 0;i < n;i++) {
		cnt[s[i] - 'a']++;
	}
	vector<int> c;
	for(int i = 0;i < 26;i++) {
		if(cnt[i] % 2) {
			c.push_back(i);
		}
	}
	int len = c.size();
	if(len == 0) {
		cout << generate(cnt) << '\n';
		return 0;
	}
	if(len % 2 == 0) {
		for(int i = 0;i < len;i++) {
			cnt[c[i]] += (i < len / 2) ? 1 : -1;
		}
		
	}
	else {
		for(int i = 0;i < len;i++) {
			if(i == len / 2)
				continue;
			else if(i < len / 2)
				cnt[c[i]]++;
			else 
				cnt[c[i]]--;
		}
	}
	cout << generate(cnt) << '\n';


	return 0;
}