/* 
** Created by Wangjy.
** https://codeforces.com/contest/349/problem/B
** 1700
** 贪心，和答案的思路完全一致，就是代码有点丑，调试的时间长了些
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
	vector<int> a(10, -1);
	for(int i = 1;i < 10;i++) {
		cin >> a[i];
	}
	vector<pii> b;
	unordered_map<int, int> m;
	for(int i = 1;i < 10;i++) {
		b.push_back({a[i], i});
		m[i] = a[i];
	}
	sort(b.begin(), b.end(), [&](pii& p, pii& q) {return p.first == q.first ? p.second > q.second : p.first < q.first;});
	string s = "";
	int len = 0;
	for(int i = 0;i < b.size();i++) {
		int num = n / b[i].first;
		int r = n % b[i].first;
		for(int j = 0;j < num;j++) {
			s += to_string(b[i].second);
		}
		len += num;
		n = r;
	}
	for(int i = 0;i < s.size();i++) {
		int num = s[i] - '0';
		for(int j = 9;j > 0;j--) {
			if(j > num) {
				if(n + a[num] >= a[j]) {
					s[i] = '0' + j;
					n -= a[j] - a[num];
					break;
				}
			}
		}
	}
	if(len == 0) {
		cout << -1 << '\n';
	}
	else {
		sort(s.begin(), s.end(), greater<char>());
		cout << s << '\n';
	}

	return 0;
}