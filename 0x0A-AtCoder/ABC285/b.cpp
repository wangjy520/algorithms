#include <bits/stdc++.h>
 
using namespace std;

/*
 * 可以直接输出
 */  
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int i = 1;i < n;i++) {
        int ans = 0;
        for(int j = 1;i + j <= n;j++) {
            if(s[j - 1] != s[j + i - 1])
                ans++;
            else 
                break;
        }
        cout << ans << '\n';
    }   


    return 0;
}