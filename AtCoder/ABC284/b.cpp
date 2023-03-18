#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0;i < n;i++) {
		int num;
		cin >> num;
		if(num % 2 == 1)
			ans++;
	}
	cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
} 
    
    
