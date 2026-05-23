#include <bits/stdc++.h>
using namespace std;
const int maxn = 120;
int n;
int l[maxn], r[maxn];
set<int> s;
int go(int x) {
  while (r[x]) x = r[x];
  return x;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    if (l[i] == 0) s.insert(i);
  }
  int me = *s.begin();
  s.erase(s.begin());
  while (s.size()) {
    me = go(me);
    int nex = *s.begin();
    s.erase(nex);
    r[me] = nex;
    l[nex] = me;
  }
  for (int i = 1; i <= n; i++) cout << l[i] << " " << r[i] << "\n";
  return 0;
}
