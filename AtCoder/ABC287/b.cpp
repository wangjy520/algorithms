/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

#define ls (k << 1)
#define rs ((k << 1) | 1)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> strs(n);
	for(int i = 0;i < n;i++) {
		cin >> strs[i];
	}
	unordered_set<string> ss;
	for(int i = 0;i < m;i++) {
		string t;
		cin >> t;
		ss.insert(t);
	}
	int res = 0;
	for(auto s : strs) {
		if(ss.find(s.substr(3, 3)) != ss.end()) {
			res++;
		}
	}
	cout << res << '\n';
	


	return 0;
}