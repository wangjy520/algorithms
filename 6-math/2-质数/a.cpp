// 
// Created by Wangjy.
// https://www.luogu.com.cn/problem/P5535
// Accepted
// 伯特兰-切比雪夫定理
// 
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	LL n, k;
	cin >> n >> k;
	n++;
	bool is_prime = true;
	if(k != 1) {
		for(int i = 2;i <= sqrt(k + 1);i++) {
			if((k + 1) % i == 0) {
				is_prime = false;
				break;
			}
		}
	}
	int res = 0;
	if(is_prime) {
		if(k + 1 > n / 2) {
			res = 1;
		}
		else {
			res = 2;
		}
	}
	else {
		if(k + 1 > n / 2) {
			res = 2;
		}
		else {
			res = 2;
		}
	}
	cout << res <<'\n';



	return 0;
}