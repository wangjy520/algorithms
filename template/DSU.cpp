struct DSU
{
	vector<int> p, r;
	DSU(int n) : p(n), r(n, 0) {iota(p.begin(), p.end(), 0);}
	int find(int x) {
		return x == p[x] ? x : (p[x] = find(p[x]));
	}
	bool same(int x, int y) {return find(x) == find(y);}
	void merge(int x, int y) {
		x = find(x);
		y = find(y);
		if(r[x] < r[y])
			p[x] = y;
		else
			p[y] = x;
		if(x != y && r[x] == r[y])
			r[x]++;
	}
};
