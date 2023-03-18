/* 
** Created by Wangjy.
** 
** 
** 
*/ 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	string t = "";
	for(int i = 0;i < n;i++) {
		if(s[i] == 'n' && i < n - 1 && s[i + 1] == 'a') {
			t += "nya";
			i++;
		}
		else {
			t += s[i];
		}
	}
	cout << t << '\n';
	


	return 0;
}	