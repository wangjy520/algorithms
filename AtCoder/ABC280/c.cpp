//
// Created by Wangjy.
//
#include<bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;
    for(int i = 0;i < s.size();i++) {
        if(s[i] != t[i]) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << s.size() + 1 << '\n';

    return 0;
}
