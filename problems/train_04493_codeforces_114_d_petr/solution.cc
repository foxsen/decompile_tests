#include <bits/stdc++.h>
using namespace std;
const int N = 2002;
int n;
string t, s_beg, s_end;
long long pw[N], h[N];
void pre() {
  pw[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw[i] = pw[i - 1] * 31;
  }
  for (int i = 0; t[i]; ++i) {
    h[i + 1] = h[i] + (t[i] - 'a' + 1) * pw[i];
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t >> s_beg >> s_end;
  n = t.size();
  int nb = s_beg.size();
  int ne = s_end.size();
  pre();
  long long hb = 0;
  for (int i = 0; s_beg[i]; ++i) {
    hb += (s_beg[i] - 'a' + 1) * pw[i];
  }
  hb = hb * pw[n - nb];
  long long he = 0;
  for (int i = 0; s_end[i]; ++i) {
    he += (s_end[i] - 'a' + 1) * pw[i];
  }
  he = he * pw[n - ne];
  unordered_map<long long, int> maf(n * n);
  for (int i = nb; i <= n; ++i) {
    long long cur = (h[i] - h[i - nb]) * pw[n - i];
    if (cur != hb) continue;
    for (int j = max(i, i - nb + ne); j <= n; ++j) {
      long long cur = (h[j] - h[j - ne]) * pw[n - j];
      if (cur != he) continue;
      long long sub = (h[j] - h[i - nb]) * pw[n - j];
      maf[sub]++;
    }
  }
  cout << maf.size() << "\n";
  return 0;
}
