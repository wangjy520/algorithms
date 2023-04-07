#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int n) {
    vector<int> p;
    vector<int> v;
    for(int i = 2;i <= n;i++) {
        if(!v[i]) {
            v[i] = i;
            p.push_back(i);
        }
        for(int j = 0;j < p.size();j++) {
            if(p[j] > v[i] || p[j] > n / i)
                break;
            v[i * p[j]] = p[j];
        }
    }
    return p;
}