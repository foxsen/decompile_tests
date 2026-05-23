#include <bits/stdc++.h>
using namespace std;
const int MAXN = 201;
set<int> sets[MAXN * (MAXN - 1) / 2];
vector<int> inw[MAXN * MAXN];
set<int> s, rs[MAXN];
map<int, int> a, ia;
int ans[MAXN];
int main() {
  int n, i, jj, j, k;
  cin >> n;
  int l = n * (n - 1) / 2, x, y;
  for (i = 0; i < l; ++i) {
    cin >> x;
    for (jj = 0; jj < x; ++jj) {
      cin >> y;
      sets[i].insert(y);
      s.insert(y);
    }
  }
  i = 0;
  set<int>::iterator it;
  for (it = s.begin(); it != s.end(); ++it) {
    ++i;
    a[(*it)] = i;
    ia[i] = *it;
  }
  if (n == 2) {
    cout << "1 ";
    cout << ia[1] << endl;
    cout << i - 1;
    for (j = 2; j <= i; ++j) cout << " " << ia[j];
    cout << endl;
    return 0;
  }
  for (i = 0; i < l; ++i) {
    set<int>::iterator j;
    for (j = sets[i].begin(); j != sets[i].end(); ++j) {
      inw[a[*j]].push_back(i);
    }
  }
  int ss = s.size();
  for (i = 1; i <= ss; ++i) {
    sort(inw[i].begin(), inw[i].end());
    ans[i] = i;
  }
  for (i = 1; i <= ss; ++i)
    for (j = 1; j <= ss; ++j)
      if (i != j) {
        if (inw[i].size() == inw[j].size()) {
          bool ok = true;
          l = inw[i].size();
          for (k = 0; k < l && ok; ++k) {
            if (inw[i][k] != inw[j][k]) ok = false;
          }
          if (ok) {
            int v1 = ans[i];
            int v2 = ans[j];
            for (k = 1; k <= ss; ++k)
              if (ans[k] == v1) ans[k] = v2;
          }
        }
      }
  int bb = 0;
  for (i = 1; i <= ss; ++i) {
    int v = ans[i];
    if (v != -1) {
      for (j = 1; j <= ss; ++j) {
        if (ans[j] == v) {
          rs[bb].insert(j);
          ans[j] = -1;
        }
      }
      ++bb;
    }
  }
  for (i = 0; i < bb; ++i) {
    cout << rs[i].size();
    for (it = rs[i].begin(); it != rs[i].end(); ++it) cout << " " << ia[*it];
    cout << endl;
  }
  return 0;
}
