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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m), ra(n), rb(m);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for(int i = 0;i < m;i++) {
		cin >> b[i];
	}
	int i = 0, j = 0, k = 1;
	while(i < n && j < m) {
		if(a[i] < b[j]) {
			ra[i++] = k++;
		}
		else {
			rb[j++] = k++;
		}
	}
	while(i < n)
		ra[i++] = k++;
	while(j < m)
		rb[j++] = k++;
	for(auto& i : ra) 
		cout << i << " ";
	cout << '\n';
	for(auto& i : rb)
		cout << i << " ";
	cout << '\n';
	return 0;
}