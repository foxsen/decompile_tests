#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define Ri register
typedef long long ll;

const int N = 1e5 + 100, M = 500;

int T;
ll n, k, a[N];

ll cal(ll x) {
    if (x < 3) return 0;
    return (x - 3) / 2 + 1;
}

int main() {
    scanf("%d", &T);
    for (; T; T--) {
        scanf("%lld", &n);
        ll tmp = sqrt(2 * n - 1); 
        if (tmp % 2 == 0) tmp--;
        printf("%lld\n", cal(tmp));
    }
}