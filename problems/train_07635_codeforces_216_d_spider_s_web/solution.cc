#include <bits/stdc++.h>
using namespace std;
int n, na, nb, nc;
vector<int> a, b;
vector<int> start;
int solve(vector<pair<int, int> > &c, vector<pair<int, int> > &b) {
  int nb = b.size();
  int nc = c.size();
  int ans = 0;
  sort(c.begin(), c.end());
  sort(b.begin(), b.end());
  int i = 0, j = 0;
  for (; i < nb && b[i].second; i++)
    ;
  for (; j < nc && c[j].second; j++)
    ;
  for (; i < nb && j < nc;) {
    int ii = i++, jj = j++;
    for (; i < nb && b[i].second; i++)
      ;
    for (; j < nc && c[j].second; j++)
      ;
    if (i < nb && j < nc) {
      if (ii - i != jj - j) ans++;
    }
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  b.push_back(0);
  for (int i = 0, zz = 0; i < n; i++) {
    scanf("%d", &zz);
    b.push_back(zz);
    for (int j = 0, _x; j < zz; j++) {
      scanf("%d", &_x);
      a.push_back(_x);
    }
  }
  for (int i = 0; i < n; i++) b[i + 1] += b[i];
  int ans = 0;
  vector<pair<int, int> > ta, tb;
  for (int k = 0; k < n; k++) {
    ta.clear();
    tb.clear();
    for (int i = b[k]; i < b[k + 1]; i++) {
      ta.push_back(pair<int, int>(a[i], 0));
      tb.push_back(pair<int, int>(a[i], 0));
    }
    if (k == 0) {
      for (int i = b[n - 1]; i < b[n]; i++) {
        ta.push_back(pair<int, int>(a[i], 1));
      }
    } else {
      for (int i = b[k - 1]; i < b[k]; i++) {
        ta.push_back(pair<int, int>(a[i], 1));
      }
    }
    if (k == n - 2) {
      for (int i = b[n - 1]; i < b[n]; i++) {
        tb.push_back(pair<int, int>(a[i], 1));
      }
    } else {
      for (int i = b[(k + 1) % n]; i < b[(k + 2) % n]; i++) {
        tb.push_back(pair<int, int>(a[i], 1));
      }
    }
    ans += solve(ta, tb);
  }
  cout << ans << endl;
  return 0;
}
