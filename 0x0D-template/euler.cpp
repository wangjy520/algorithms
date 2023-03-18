// 埃氏筛求欧拉函数O(nlogn)
vector<int> euler(int n) {
	vector<int> res(n + 1);
	iota(res.begin(), res.end(), 0);
	for(int i = 2;i <= n;i++) {
		if(res[i] == i) {
			for(int j = i;j <= n; j += i) {
				res[j] = res[j] / i * (i - 1);
			}
		}
	}
	return res;
}
// 线性筛求欧拉函数O(n)
vector<int> euler(int n) {
	vector<int> phi(n + 1), v(n + 1), prime;
	iota(v.begin(), v.end(), 0);
	int cnt = 0;
	for(int i = 2;i <= n;i++) {
		if(v[i] == i) {
			prime.push_back(i);
			cnt++;
			phi[i] = i - 1;
		}
		for(int j = 0;j < cnt;j++) {
			if(prime[j] > i || prime[j] > n / i)
				break;
			v[i * prime[j]] = prime[j];
			phi[i * prime[j]] = phi[i] * (i % prime[j] ? (prime[j] - 1) : prime[j]);
		}
	}
	return phi;
}