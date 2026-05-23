#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 300000;
int n;
int a[MAXN];
int nxt[MAXN + 1];
map<int, int> mp[MAXN + 1];
int mpidx[MAXN + 1];
int len[MAXN + 1];
long long solve() {
  nxt[n] = -1;
  mpidx[n] = n, mp[n].clear();
  for (int i = n - 1; i >= 0; --i) {
    int idx = mpidx[i + 1];
    auto it = mp[idx].find(a[i]);
    if (it != mp[idx].end()) {
      nxt[i] = it->second + 1;
      assert(mpidx[nxt[i]] != -1);
      mpidx[i] = mpidx[nxt[i]];
      mpidx[nxt[i]] = -1;
      if (nxt[i] < n) mp[mpidx[i]][a[nxt[i]]] = nxt[i];
    } else {
      nxt[i] = -1;
      mpidx[i] = i, mp[i].clear();
    }
    mp[mpidx[i]][a[i]] = i;
  }
  len[n] = 0;
  for (int i = n - 1; i >= 0; --i) {
    len[i] = nxt[i] == -1 ? 0 : 1 + len[nxt[i]];
  }
  long long ret = 0;
  for (int i = (0); i < (n); ++i) ret += len[i];
  return ret;
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]);
  printf("%lld\n", solve());
}
int main() {
  int ncase;
  scanf("%d", &ncase);
  for (int i = (1); i <= (ncase); ++i) run();
  return 0;
}
