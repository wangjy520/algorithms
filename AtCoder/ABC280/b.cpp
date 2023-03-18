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
    vector<int> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    cout << a[0] << " ";
    for(int i = 1;i < n;i++) {
        cout << a[i] - a[i - 1] << " ";
    }

    return 0;
}
