#include <bits/stdc++.h>
using namespace std;
const int N = 11;
const int M = 2050;
const int pr = 1993;
const int mod = 1000000031;
vector<long long> st[N];
set<long long> dif;
int l[N], r[N];
long long hs[M], deg[M], ls[M * M];
void proc(int id, string s) {
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    long long h = 0;
    for (int j = i; j < n; j++) {
      h = (h + s[j]) * pr;
      st[id].push_back(h);
    }
  }
}
int main() {
  string s;
  int n;
  cin >> s >> n;
  for (int i = 0; i < n; i++) {
    string p;
    cin >> p >> l[i] >> r[i];
    proc(i, p);
  }
  for (int i = 0; i < n; i++) {
    sort(st[i].begin(), st[i].end());
  }
  int ans = 0;
  int len = (int)s.size();
  deg[0] = 1;
  for (int i = 0; i < len; i++) {
    hs[i + 1] = (hs[i] + s[i]) * pr;
    deg[i + 1] = deg[i] * pr;
  }
  int kk = 0;
  for (int i = 0; i < len; i++)
    for (int j = i; j < len; j++) ls[kk++] = hs[j + 1] - hs[i] * deg[j - i + 1];
  sort(ls, ls + kk);
  kk = unique(ls, ls + kk) - ls;
  int cnt = 0;
  for (int it = 0; it < kk; it++) {
    cnt++;
    if (cnt == 100) {
      if (double(clock()) / double(CLOCKS_PER_SEC) > 3.95) break;
      cnt = 0;
    }
    long long h = ls[it];
    bool ok = 1;
    for (int k = 0; k < n; k++) {
      int cnt = upper_bound(st[k].begin(), st[k].end(), h) -
                lower_bound(st[k].begin(), st[k].end(), h);
      if (!(l[k] <= cnt && cnt <= r[k])) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
