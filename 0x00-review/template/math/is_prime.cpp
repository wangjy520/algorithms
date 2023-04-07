#include<bits/stdc++.h>
using namespace std;
/**
 * 判断一个数是不是质数
 * 试除法
 * 时间复杂度 ：根号n
*/
bool solve(int n) {
    for(int i = 2;i <= sqrt(n);i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}