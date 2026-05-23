#include <bits/stdc++.h>
using namespace std;
int n;
int a[400005];
int l[400005], r[400005];
int aintlz[1600005], lazy[1600005];
int aint[800005];
int h[400005];
void init(int nod, int l, int r) {
  if (l == r)
    aint[nod] = l;
  else {
    int mid = (l + r) / 2;
    init(2 * nod, l, mid);
    init(2 * nod + 1, mid + 1, r);
    if (a[aint[2 * nod]] < a[aint[2 * nod + 1]])
      aint[nod] = aint[2 * nod];
    else
      aint[nod] = aint[2 * nod + 1];
  }
}
int query(int nod, int l, int r, int x, int y) {
  if (l >= x && r <= y)
    return aint[nod];
  else {
    int mid = (l + r) / 2;
    int p1, p2;
    if (x <= mid)
      p1 = query(2 * nod, l, mid, x, y);
    else
      p1 = -1;
    if (y > mid)
      p2 = query(2 * nod + 1, mid + 1, r, x, y);
    else
      p2 = -1;
    if (p1 == -1)
      return p2;
    else if (p2 == -1)
      return p1;
    else {
      if (a[p1] < a[p2])
        return p1;
      else
        return p2;
    }
  }
}
void tree(int x, int y, int lev) {
  if (x == y)
    h[x] = lev;
  else {
    int pmin = query(1, 1, n, x, y);
    h[pmin] = lev;
    if (pmin > x) tree(x, pmin - 1, lev + 1);
    if (pmin < y) tree(pmin + 1, y, lev + 1);
  }
}
void initlz(int nod, int l, int r) {
  if (l == r)
    aintlz[nod] = h[l];
  else {
    int mid = (l + r) / 2;
    initlz(2 * nod, l, mid);
    initlz(2 * nod + 1, mid + 1, r);
    aintlz[nod] = max(aintlz[2 * nod], aintlz[2 * nod + 1]);
  }
}
void updatelz(int nod, int l, int r, int x, int y, int val) {
  if (l > r) return;
  if (lazy[nod] != 0) {
    aintlz[nod] += lazy[nod];
    if (l < r) {
      lazy[2 * nod] += lazy[nod];
      lazy[2 * nod + 1] += lazy[nod];
    }
    lazy[nod] = 0;
  }
  if (l > y || r < x) return;
  if (l >= x && r <= y) {
    aintlz[nod] += val;
    if (l < r) {
      lazy[2 * nod] += val;
      lazy[2 * nod + 1] += val;
    }
    return;
  }
  int mid = (l + r) / 2;
  updatelz(2 * nod, l, mid, x, y, val);
  updatelz(2 * nod + 1, mid + 1, r, x, y, val);
  aintlz[nod] = max(aintlz[2 * nod], aintlz[2 * nod + 1]);
}
int querylz(int nod, int l, int r, int x, int y) {
  if (x == 0) return 0;
  if (lazy[nod] != 0) {
    aintlz[nod] += lazy[nod];
    if (l < r) {
      lazy[2 * nod] += lazy[nod];
      lazy[2 * nod + 1] += lazy[nod];
    }
    lazy[nod] = 0;
  }
  if (l >= x && r <= y)
    return aintlz[nod];
  else {
    int mid = (l + r) / 2;
    int v1 = -1, v2 = -1;
    if (x <= mid) v1 = querylz(2 * nod, l, mid, x, y);
    if (y > mid) v2 = querylz(2 * nod + 1, mid + 1, r, x, y);
    return max(v1, v2);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  init(1, 1, n);
  tree(1, n, 1);
  n *= 2;
  initlz(1, 1, n);
  l[1] = 0;
  for (int i = 2; i <= n; ++i) {
    l[i] = i - 1;
    while (a[l[i]] >= a[i]) l[i] = l[l[i]];
  }
  r[n] = n + 1;
  for (int i = n - 1; i >= 1; --i) {
    r[i] = i + 1;
    while (a[r[i]] >= a[i]) r[i] = r[r[i]];
  }
  int hmin = aintlz[1];
  int shl = 0;
  for (int i = 1; i < n / 2; ++i) {
    if (r[i] < i + n / 2) updatelz(1, 1, n, i + 1, r[i] - 1, -1);
    if (l[i + n / 2] > i) updatelz(1, 1, n, l[i + n / 2] + 1, i + n / 2 - 1, 1);
    h[i + n / 2] = querylz(1, 1, n, l[i + n / 2], l[i + n / 2]) + 1;
    updatelz(1, 1, n, i + n / 2, i + n / 2, h[i + n / 2]);
    h[i] = -querylz(1, 1, n, i, i);
    updatelz(1, 1, n, i, i, h[i]);
    if (aintlz[1] < hmin) {
      hmin = aintlz[1];
      shl = i;
    }
  }
  cout << hmin << " " << shl;
  return 0;
}
