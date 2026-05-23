#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rd(T &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 - '0' + c, c = getchar();
  x *= f;
}
const int mod = 1e9 + 7;
inline int Pow(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = x * (long long)x % mod)
    if (y & 1) res = res * (long long)x % mod;
  return res;
}
const int inv100 = Pow(100, mod - 2);
unordered_map<long long, int> f[8];
int mp[8][8], n;
int cnt[1 << 7], id[1 << 7], siz[1 << 7], pos[8][1 << 7];
int main() {
  rd(n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      rd(mp[i][j]), mp[i][j] = mp[i][j] * (long long)inv100 % mod;
  for (int S = 0; S < (1 << n); ++S) {
    cnt[S] = cnt[S >> 1] + (S & 1);
    pos[cnt[S]][id[S] = siz[cnt[S]]++] = S;
  }
  f[0][1] = 1;
  for (int i = 0; i < n; ++i) {
    vector<int> item[8];
    for (int x = 0; x < n; ++x)
      for (int k = 0; k < siz[i]; ++k)
        if (!(pos[i][k] >> x & 1)) item[x].push_back(k);
    for (auto it = f[i].begin(); it != f[i].end(); ++it)
      for (int S = 0; S < (1 << n); ++S) {
        int v = it->second;
        long long u = 0;
        for (int x = 0; x < n; ++x)
          if (S >> x & 1) {
            v = v * (long long)mp[i][x] % mod;
            for (int t = 0; t < item[x].size(); ++t)
              if ((it->first) >> item[x][t] & 1)
                u |= 1ll << id[pos[i][item[x][t]] | 1 << x];
          } else
            v = v * (long long)(1 - mp[i][x]) % mod;
        if (!u) continue;
        (f[i + 1][u] += v) %= mod;
      }
  }
  printf("%d\n", (f[n][1] + mod) % mod);
  return 0;
}
