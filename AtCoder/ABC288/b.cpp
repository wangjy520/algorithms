/* 
** Created by Wangjy.
** 
** 
** 
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
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<string> ss;
	for(int i = 0;i < n;i++) {
		string s;
		cin >> s;
		ss[i] = s;
	}
	sort(ss.begin(), ss.end(), [&](string a, string b) {
		return strcmp(a, b);
	});
	for(int i = 0;i < k;i++) {
		cout << ss[i] << '\n';
	}
	

	return 0;
}