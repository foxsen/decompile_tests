#include <bits/stdc++.h>

int n, x, xi, ans;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &xi);
        ans = gcd(std::abs(xi - x), ans);
    }
    printf("%d\n", ans);
    return 0;
}
