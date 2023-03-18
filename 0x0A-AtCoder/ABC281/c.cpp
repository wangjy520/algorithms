//
// Created by Wangjy.
//
#include<bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    long long t;
    cin >> t;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) {
        cin >> nums[i];
    }
    vector<long long> pre(n + 1, 0);
    for(int i = 1;i <= n;i++) {
        pre[i] = pre[i - 1] + nums[i - 1];
    }
    t = t % pre[n];
    for(int i = 1;i <= n;i++) {
        if(t < pre[i]) {
            cout << i << " " << t - pre[i - 1] << '\n';
            return 0;
        }
    }

    return 0;
}
