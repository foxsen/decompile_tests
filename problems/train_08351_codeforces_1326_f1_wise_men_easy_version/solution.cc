#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;
const int MOD = 998244353;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<bitset<15>> G(n);
  vector<ll> ans(1 << (n - 1));
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    reverse(begin(x), end(x));
    G[i] = bitset<15>(x);
  }
  for (int Mask = 0; Mask < (1 << n); ++Mask) {
    if (__builtin_popcount(Mask) != n / 2) continue;
    vector<int> s1, s2, m1(15, 0), m2(15, 0);
    int k1 = 0, k2 = 0;
    for (int i = 0; i < n; ++i) {
      if (Mask & (1 << i)) {
        s2.push_back(i);
        m2[i] = k2++;
      } else {
        s1.push_back(i);
        m1[i] = k1++;
      }
    }
    int ct[1 << (s1.size() - 1)][s1.size()];
    memset(ct, 0, sizeof ct);
    int ct2[1 << (s2.size() - 1)][s2.size()];
    memset(ct2, 0, sizeof ct2);
    do {
      int mask = 0;
      for (int i = 0; i + 1 < s1.size(); ++i) {
        mask *= 2;
        if (G[s1[i]][s1[i + 1]]) mask += 1;
      }
      ++ct[mask][m1[s1.back()]];
    } while (next_permutation(begin(s1), end(s1)));
    do {
      int mask = 0;
      for (int i = 0; i + 1 < s2.size(); ++i) {
        mask *= 2;
        if (G[s2[i]][s2[i + 1]]) mask += 1;
      }
      ++ct2[mask][m2[s2[0]]];
    } while (next_permutation(begin(s2), end(s2)));
    for (int mask1 = 0; mask1 < (1 << (s1.size() - 1)); ++mask1) {
      for (int i = 0; i < s1.size(); ++i) {
        if (!ct[mask1][i]) continue;
        for (int mask2 = 0; mask2 < (1 << (s2.size() - 1)); ++mask2) {
          for (int j = 0; j < s2.size(); ++j) {
            if (!ct2[mask2][j]) continue;
            int mask = mask1;
            mask *= 2;
            if (G[s1[i]][s2[j]]) ++mask;
            mask <<= (s2.size() - 1);
            mask += mask2;
            ans[mask] += ct[mask1][i] * ct2[mask2][j];
          }
        }
      }
    }
  }
  for (int i = 0; i < (1 << (n - 1)); ++i) cout << ans[i] << ' ';
}
