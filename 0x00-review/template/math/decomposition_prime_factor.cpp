#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> solve(int n) {
    vector<pair<int, int>> ans;
    for(int i = 2;i <= sqrt(n);i++) {
        if(n % i == 0) {
            int cnt = 0;
            while(n % i == 0) {
                cnt++;
                n /= i;
            }
            ans.push_back({i, cnt});
        }
    }
    if(n > 1)
        ans.push_back({n, 1});
    return ans;
}