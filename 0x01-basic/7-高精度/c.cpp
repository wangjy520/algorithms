// 
// Created by Wangjy.
// https://www.luogu.com.cn/problem/P1303
// 高精度乘法，两个非负整数
// Accepted
// 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

void mul(string sa, string st) {
	if(sa == "0" || st == "0") {
		cout << "0" << '\n';
		return ;
	}
	int m = sa.size(), n = st.size();
	vector<int> a(m, 0), b(n, 0);
	for(int i = m - 1, j = 0;i >= 0;i--, j++) {
		a[j] = sa[i] - '0';
	}
	for(int i = n - 1, j = 0;i >= 0;i--, j++) {
		b[j] = st[i] - '0';
	}
	vector<int> res(m + n, 0);
	for(int i = 0;i < m;i++) {
		for(int j = 0;j < n;j++) {
			res[i + j] += a[i] * b[j];
		}
	}
	for(int i = 0;i < m + n;i++) {
		if(res[i] >= 10) {
			res[i + 1] += res[i] / 10;
			res[i] %= 10;
		}
	}
	bool fs = true;
	for(int i = m + n - 1;i >= 0;i--) {
		if(res[i] == 0 && fs) {
			continue;
		}
		else {
			fs = false;
			cout << res[i];
		}
	}
	cout << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	mul(a, b);


	return 0;
}