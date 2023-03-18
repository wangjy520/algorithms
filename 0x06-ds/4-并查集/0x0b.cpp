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

struct DSU
{
	vector<int> p;
	DSU(int n) : p(n) {iota(p.begin(), p.end(), 0);}
	int find(int x) {
		return x == p[x] ? x : (p[x] = find(p[x]));
	}
	bool same(int x, int y) {return find(x) == find(y);}
	void merge(int x, int y) {
		p[y] = x;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	DSU dsu(5e4 + 10);
	unordered_map<string, int> m;
	unordered_map<int, string> mm;
	int cur = -1;
	int cnt = 1;
	while(s != "$") {
		string t = s.substr(1);
		if(m.find(t) == m.end()) {
			m[t] = cnt;
			mm[cnt] = t;
			cnt++;
		}
		int num = m[t];
		if(s[0] == '#') {
			cur = num;
		}
		else if(s[0] == '+') {
			dsu.merge(cur, num);
		}
		else {
			cout << t << " " << mm[dsu.find(num)] << '\n';
		}
		cin >> s;
	}

	return 0;
}