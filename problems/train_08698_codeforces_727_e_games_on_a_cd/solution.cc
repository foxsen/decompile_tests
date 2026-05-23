#include <bits/stdc++.h>
using namespace std;
int N, K, G, f[1100100];
char s[2200200], t[100100];
map<long long, int> id;
bool did[100100];
vector<int> v;
struct hash {
  long long cum[2200200], rcum[2200200], MOD, M = 2200100, po[2200200];
  void init(long long mod) {
    MOD = mod, po[0] = 1;
    for (int i = 1; i < 2200200; i++) po[i] = (po[i - 1] * 137) % MOD;
    for (int i = (0); i < (2 * N * K); i++) {
      cum[i] = (po[i] * s[i]) % MOD;
      if (i) cum[i] = (cum[i] + cum[i - 1]) % MOD;
    }
  }
  long long q(int l, int r) {
    long long res = (cum[r] - (l ? cum[l - 1] : 0) + MOD);
    res = (res * po[M - l]) % MOD;
    return res;
  }
  long long force() {
    long long h = 0;
    for (int i = (0); i < (K); i++) {
      long long x = po[i] * t[i] % MOD;
      h = (h + x) % MOD;
    }
    return h * po[M] % MOD;
  }
} a, b;
int main() {
  scanf("%d %d %s", &N, &K, s);
  for (int i = (0); i < (N * K); i++) s[i + N * K] = s[i];
  a.init(1000000007ll), b.init(1000000009ll);
  scanf("%d", &G);
  for (int z = (0); z < (G); z++) {
    scanf(" %s", t);
    long long x = a.force() * (1000000009ll) + b.force();
    id[x] = z;
  }
  for (int i = (0); i < (N * K); i++) {
    long long mh = a.q(i, i + K - 1) * (1000000009ll) + b.q(i, i + K - 1);
    if (id.count(mh))
      f[i] = id[mh];
    else
      f[i] = -1;
  }
  for (int st = (0); st < (K); st++) {
    bool ok = 1;
    for (int i = st; i < N * K; i += K) {
      if (f[i] == -1) {
        ok = 0;
        break;
      }
      if (did[f[i]]) {
        ok = 0;
        break;
      }
      did[f[i]] = 1;
      v.push_back(f[i]);
    }
    if (ok) {
      puts("YES");
      for (int i : v) printf("%d ", 1 + i);
      puts("");
      return 0;
    }
    while (v.size()) did[v.back()] = 0, v.pop_back();
  }
  puts("NO");
  return 0;
}
