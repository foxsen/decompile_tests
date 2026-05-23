#include<bits/stdc++.h>
using namespace std;

int _t;

int n, m;
int k[300055], c[300055];

long long check(int cnt) {
    long long ret = 0;
    for (int i = 0; i < cnt; i++) {
        ret += c[k[i]];
    }
    for (int i = cnt; i < n; i++) {
        ret += c[i - cnt];
        if (i - cnt > k[i]) {
            return 0;
        }
    }

    return ret;
}

int main() {
  scanf("%d", &_t);
  while (_t--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", k + i);
        k[i]--;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", c + i);
    }
    sort(k, k + n);
    
    int lo = -1, hi = n;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        long long res = check(mid);
        // fprintf(stderr, "check(%d) = %lld\n", mid, res);
        if (res) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    long long ans = check(hi);
    // fprintf(stderr, "check(%d) = %lld\n", hi, ans);

    for (int i = 0; i < n - hi; i++) {
        if (c[n - hi - 1 - i] >= c[k[hi + i]]) {
            ans -= c[n - hi - 1 - i];
            ans += c[k[hi + i]];
        } else {
            break;
        }
    }

    printf("%lld\n", ans);
  }
}