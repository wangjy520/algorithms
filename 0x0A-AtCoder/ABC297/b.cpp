/* 
** Created by Wangjy.
*/ 
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	vector<int> cnt(26, 0);
	for(int i = 0;i < 8;i++) {
		cnt[s[i] - 'A']++;
	}
	if(cnt['K' - 'A'] != 1 || cnt['Q' - 'A'] != 1 || cnt['B' - 'A'] != 2 || cnt['R' - 'A'] != 2 || cnt['N' - 'A'] != 2) {
		cout << "No\n";
		return 0;
	} 
	int id1 = -1, id2 = -1, id3 = -1;
	for(int i = 0;i < 8;i++) {
		if(s[i] == 'R') {
			if(id1 == -1) {
				id1 = i;
			}
			else {
				id2 = i;
			}
		}
		if(s[i] == 'K') {
			id3 = i;
		}
	}
	cout << (id3 > id1 && id3 < id2 ? "Yes" : "No") << '\n';
	return 0;
}