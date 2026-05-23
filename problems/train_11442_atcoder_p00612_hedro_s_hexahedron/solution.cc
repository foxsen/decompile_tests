/*
 * Author: Dumbear
 * Created Time:  2011/8/31 14:29:36
 * File Name: H.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

long long n;

bool solve();

int main() {
    while (solve());
    return 0;
}

bool solve() {
    scanf("%lld", &n);
    if (n == 0)
        return false;
    long long cnt = n - 1;
    for (long long i = 1; ; ++i) {
        if (i * i * 2 >= n)
            break;
        long long m = n / 2 / i;
        if (m * i * 2 == n)
            --m;
        cnt += (m - i) * 2 + 1;
    //printf("-- %I64d\n", cnt);
    }
    //printf("-- %I64d\n", cnt);
    printf("%lld\n", cnt * 8 + 8 * n);
    return true;
}