#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int calc_order(long long a, long long P, const vector<pair<long long, long long> > &pf) {
    int res = P - 1;
    for (auto pa : pf) {
        int p = pa.first;
        while (res % p == 0 && modpow(a, res/p, P) == 1) res /= p;
    }
    return res;
}

int GCD(int a, int b) {
    return b ? GCD(b, a % b) : a;
}

int main() {
    int P, T; scanf("%d %d", &P, &T);
    auto pf = prime_factorize(P-1);

    for (int CASE = 0; CASE < T; ++CASE) {
        int N; scanf("%d", &N);
        int gcd = P-1;
        for (int i = 0; i < N; ++i) {
            int G; scanf("%d", &G);
            gcd = GCD(gcd, (P-1)/calc_order(G, P, pf));
        }
        int A; scanf("%d", &A);
        int ga = (P-1)/calc_order(A, P, pf);
        if (ga % gcd == 0) cout << 1 << endl;
        else cout << 0 << endl;
    }
}

