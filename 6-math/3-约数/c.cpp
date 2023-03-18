// 
// Created by Wangjy.
// 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	unordered_map<int, int> m;
	for(int i = 0;i < n;i++) {
		int num;
		cin >> num;
		m[num]++;
	}
	vector<int> res(n, 1);
	for(int i = 2;i <= 1e6;i++) {
		int sum = 0;
		for(int j = i;j <= 1e6 / i;j++) {
			int mul = i * j;
			int cnt = m[mul];
			for(int k = 1;k <= cnt;k++) {
				if(sum + k < n)
					res[sum + k] = max(res[sum + k], i);
			}
			sum += cnt;
		}
	}
	for(auto ans : res) {
		cout << ans << '\n';
	}


	return 0;
}