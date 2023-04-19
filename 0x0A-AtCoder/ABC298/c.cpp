/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	vector<map<int, int>> v(n + 1);
	for(int i = 1;i <= n;i++) {
		map<int, int> m;
		v[i] = m;
	}
	unordered_map<int, set<int>> s;
	while(q--) {
		int op;
		cin >> op;
		if(op == 1) {
			int i, j;
			cin >> i >> j;
			v[j][i]++;
			s[i].insert(j);
		}
		else if(op == 2) {
			int i;
			cin >> i;
			for(auto& p : v[i]) {
				for(int j = 0;j < p.second;j++) {
					cout << p.first << " ";
				}
			}
			cout << '\n';
		}
		else {
			int i;
			cin >> i;
			for(auto& vv : s[i]) {
				cout << vv << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}