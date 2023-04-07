#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> p;
	vector<bool> v(n + 1, true);
	for(int i = 2;i <= n;i++) {
		if(v[i]) {
			p.push_back(i);
			for(int j = i * i;j <= n;j += i) {
				v[j] = false;
			}
		}
	}
	int q;
	cin >> q;
	for(int i = 0;i < q;i++) {
		int k;
		cin >> k;
		cout << p[k - 1] <<'\n';
	}

	return 0;
}