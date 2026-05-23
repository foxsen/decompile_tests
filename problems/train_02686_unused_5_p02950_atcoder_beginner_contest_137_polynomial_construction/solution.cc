#include <iostream>

using namespace std;

int bexp(int a, int x, int p) {
    if (x == 0) {
        return 1;
    }
    if (x % 2 == 1) {
        return a * bexp(a, x - 1, p) % p;
    }
    int t = bexp(a, x / 2, p);
    return t * t % p;
}

int inv(int a, int p) {
    return bexp(a, p - 2, p);
}

int main() {
    int p;
    cin >> p;
    int a[p];
    for (int i = 0; i < p; i++) {
        cin >> a[i];
    }

    int c[p][p];
    for (int i = 0; i < p; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % p;
        }
    }

    int e[p][p];
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            e[i][j] = j == 0 ? 1 : e[i][j-1] * i % p;
        }
    }

    int fac[p];
    for (int i = 0; i < p; i++) {
        fac[i] = i == 0 ? 1 : fac[i-1] * i % p;
    }

    int b[p];
    for (int i = p - 1; i >= 0; i--) {
        int x = 0, y = 0;
        int neg = 1;
        for (int j = i; j >= 0; j--) {
            y = ((y + a[j] * c[i][j] * neg) % p + p) % p;
            neg = -neg;
        }
        b[i] = y * inv(fac[i], p) % p;

        for (int j = 0; j < p; j++) {
            a[j] = ((a[j] - b[i] * e[j][i]) % p + p) % p;
        }
    }

    for (int i = 0; i < p; i++) {
        cout << b[i] << (i == p - 1 ? '\n' : ' ');
    }

    return 0;
}
