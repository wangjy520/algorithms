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

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	vector<int> b(m);
	unordered_map<int, int> mm;
	for(int i = 0;i < m;i++) {
		cin >> b[i];
		mm[b[i]]++;
	}
	sort(a.begin(), a.end());
	int res = 0;
	for(int i = 0;i < n;i++) {
		if(mm.find(a[i] - 1) != mm.end()) {
			if(mm[a[i] - 1] > 0) {
				res++;
				mm[a[i] - 1]--;
				continue;
			}
		}
		if(mm.find(a[i]) != mm.end()) {
			if(mm[a[i]] > 0) {
				res++;
				mm[a[i]]--;
				continue;
			}
		}
		if(mm.find(a[i] + 1) != mm.end()) {
			if(mm[a[i] + 1] > 0) {
				res++;
				mm[a[i] + 1]--;
			}
		}
	}
	cout << res << '\n';



	return 0;

}