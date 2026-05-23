#include <bits/stdc++.h>
using namespace std;
int n, m;
int g[100000], cnt[100000];
int v[100000], b[100000];
int s[100005], sc[100005], sz;
bool used[100005] = {}, dead[100005] = {}, marked[100005] = {};
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (int)(n); ++i) scanf("%d", g + i), --g[i], cnt[i] = 1;
  for (int i = 0; i < (int)(m); ++i) scanf("%d", v + i);
  for (int i = 0; i < (int)(m); ++i) scanf("%d", b + i);
  int prevAns = 0;
  for (int q = 0; q < (int)(m); ++q) {
    int a = (v[q] + prevAns - 1) % n;
    int ans = 0;
    int rem = b[q];
    --rem;
    if (!used[a]) {
      ans = 1;
      used[a] = true;
    }
    while (true) {
      sz = 0;
      while (used[g[a]]) {
        if (marked[a] || dead[a]) break;
        s[sz] = a;
        marked[a] = true;
        rem -= cnt[a];
        a = g[a];
        ++sz;
      }
      if (marked[a] || dead[a]) {
        for (int i = 0; i < (int)(sz); ++i) dead[s[i]] = true;
        for (int i = 0; i < (int)(sz); ++i) marked[s[i]] = false;
        break;
      }
      for (int i = 0; i < (int)(sz); ++i) marked[s[i]] = false;
      for (int i = sz - 1; i >= 0; --i) {
        cnt[s[i]] += cnt[g[s[i]]];
        g[s[i]] = g[g[s[i]]];
      }
      rem -= cnt[a];
      if (rem < 0) {
        break;
      }
      a = g[a];
      used[a] = true;
      ++ans;
    }
    printf("%d\n", ans);
    prevAns = ans;
  }
  return 0;
}
