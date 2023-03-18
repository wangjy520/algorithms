/* 
** Created by Wangjy.
** 
** rrrar
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
	LL a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	LL res = 0;
	if(a < b) {
		int left = 1;
		int right = 0;
		int i = 1;
		while(i < n) {
			if(s[i] == s[i - 1]) {
				left++;
			}
			else 
				break;
			i++;
		}
		if(i == n) {
			res = 0;
		}
		else {
			i = n - 1;
			while(i >= 0) {
				if(s[i] == s[0]) {
					right++;
				}
				else
					break;
				i--;
			}
			
			res += a * ((left - right) / 2);
		}

	}
	
	for(int l = 0, r = n - 1;l < r;l++, r--) {
		if(s[l] != s[r])
			res += b;
	}
	
	cout << res << '\n';
	


	return 0;
}