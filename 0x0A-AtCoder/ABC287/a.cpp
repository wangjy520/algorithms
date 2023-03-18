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


	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 0;i < n;i++) {
		string s;
		cin >> s;
		cnt += (s == "For" ? 1 : 0);
	}
	cout << (cnt > n / 2 ? "Yes" : "No") << '\n';


	return 0;
}