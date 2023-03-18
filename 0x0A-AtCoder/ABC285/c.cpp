#include <bits/stdc++.h>
#define LL long long
#define pii pair<int, int>
using namespace std;

int main() {
    string s;
    cin >> s;

    LL res = 0L;
    int n = s.size();
    for(auto ch : s) {
        res = res * 26 + (LL) (ch - 'A' + 1);
    }
    cout << res << '\n';

    return 0;
}