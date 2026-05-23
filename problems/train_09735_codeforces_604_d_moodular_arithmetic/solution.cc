#include <bits/stdc++.h>
using namespace std;
int fac[1000010], cycles[1000010], parent[1000010];
bool vis[1000010];
long long k, p;
long long exp_(long long base, int e) {
  long long res = 1;
  while (e) {
    if (e & 1) {
      res = (res % 1000000007 * base % 1000000007) % 1000000007;
    }
    base = (base % 1000000007 * base % 1000000007) % 1000000007;
    e >>= 1;
  }
  return res;
}
int dfs(int u) {
  if (vis[u]) {
    return 0;
  }
  vis[u] = true;
  return 1 + dfs(parent[u]);
}
int main() {
  scanf("%I64d %I64d", &p, &k);
  for (int i = 0; i <= p; i++) fac[i] = 0;
  for (int i = 2; i <= p; i++) {
    if (fac[i]) {
      continue;
    }
    fac[i] = i;
    for (int j = i + i; j <= p; j += i) {
      if (!fac[j]) {
        fac[j] = i;
      }
    }
  }
  for (int i = 0; i < p; i++) vis[i] = false;
  for (int i = 0; i < p; i++) {
    if (!vis[i]) {
      vis[i] = true;
      int len = 1;
      for (long long j = (i * k) % p; !vis[j]; j = (j * k) % p) {
        vis[j] = true;
        len++;
      }
      cycles[len] += len;
    }
  }
  for (int i = 2; i < p; i++) {
    cycles[i] += cycles[i / fac[i]];
  }
  for (int i = 0; i < p; i++) {
    parent[(i * k) % p] = i;
    vis[i] = false;
  }
  map<int, int> mp;
  for (int i = 0; i < p; i++) {
    if (!vis[i]) {
      mp[dfs(i)]++;
    }
  }
  long long ans = 1;
  for (map<int, int>::iterator itr = mp.begin(); itr != mp.end(); itr++) {
    ans =
        (ans % 1000000007 * exp_((long long)cycles[itr->first], itr->second)) %
        1000000007;
  }
  printf("%I64d\n", ans);
  return 0;
}
