#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100200];
int b[100200], prev[100200], kk[100200];
int i, j, k, n, m, x;
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first < b.first) {
    return true;
  } else if (a.first == b.first) {
    if (a.second > b.second)
      return true;
    else
      return false;
  }
  return false;
}
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> b[i];
    a[i] = make_pair(b[i], i);
  }
  sort(a, a + n, cmp);
  int okk, mm = 0, mi = 0, pred, predi;
  mm = a[0].first;
  mi = a[0].second;
  kk[mi] = 0;
  int next = 0;
  pred = a[0].first;
  predi = a[0].second;
  i = 1;
  int mii = 0;
  while (i < n) {
    next = max(a[i].second, next);
    while (mm == a[i].first) {
      if (a[i].second < predi && a[i].first > pred)
        kk[a[i].second] = predi - a[i].second;
      i++;
    }
    next = max(a[i].second, next);
    pred = mm;
    predi = mi;
    mi = max(mi, next);
    mm = b[mi];
    if (a[i].second < mi && a[i].first > mm) kk[a[i].second] = mi - a[i].second;
    i++;
  }
  for (i = 0; i < n; i++) {
    cout << kk[i] - 1 << " ";
  }
  return 0;
}
