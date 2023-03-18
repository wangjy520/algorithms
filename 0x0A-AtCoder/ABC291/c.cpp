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

string get(int i, int j) {
	return to_string(i) + "-" + to_string(j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	unordered_set<string> ss;
	ss.insert(get(0, 0));
	int x = 0, y = 0;
	for(auto ch : s) {
		if(ch == 'U')
			x--;
		else if(ch == 'D')
			x++;
		else if(ch == 'R')
			y++;
		else
			y--;
		string str = get(x, y);
		if(ss.find(str) != ss.end()) {
			cout << "Yes" << '\n';
			return 0;
		}
		else {
			ss.insert(str);
		}
	}
	cout << "No" << '\n';

	return 0;
}