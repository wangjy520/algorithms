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

bool check(string s) {
	int n = s.size();
	for(int i = 1;i < n;i++) {
		if(abs(s[i] - s[i - 1]) == 1) {
			return false;
		}
	}
	return true;
}

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	sort(s.begin(), s.end());
	int l = 0, r = n - 1;
	string t1 = "", t2 = "";
	while(l <= r) {
		if(l <= r) {
			t1 += s[l];
			l++;
		}
		if(l <= r) {
			t1 += s[r];
			r--;
		}
	}
	if(check(t1)) {
		cout << t1 << '\n';
		return ;
	}
	else {
		char ch = t1.back();
		t1.pop_back();
		t1 = ch + t1;
		if(check(t1)) {
			cout << t1 << '\n';
			return ;
		}
	}
	l = 0;
	r = n - 1;
	while(l <= r) {
		if(l <= r) {
			t2 += s[r];
			r--;
		}
		if(l <= r) {
			t2 += s[l];
			l++;
		}
	}
	if(check(t2)) {
		cout << t2 << '\n';
		return ;
	}
	else {
		char ch = t2.back();
		t2.pop_back();
		t2 = ch + t2;
		if(check(t2)) {
			cout << t2 << '\n';
			return ;
		}
	}
	cout << "No answer" << '\n';
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