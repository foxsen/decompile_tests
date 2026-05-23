#include <bits/stdc++.h>

using namespace std;

struct SegmentTree
{
  vector< set< int > > seg, lazy;
  int sz;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.resize(2 * sz - 1);
    lazy.resize(2 * sz - 1);
  }

  bool query(int a, int b, int low, int high, int k, int l, int r)
  {
    if(a >= r || b <= l) return (true);
    if(lazy[k].lower_bound(low) != lazy[k].lower_bound(high)) return (false);
    if(a <= l && r <= b) return (seg[k].lower_bound(low) == seg[k].lower_bound(high));
    return (query(a, b, low, high, 2 * k + 1, l, (l + r) >> 1) &&
            query(a, b, low, high, 2 * k + 2, (l + r) >> 1, r));
  }

  void add(int a, int b, int x, int k, int l, int r)
  {
    if(a >= r || b <= l) {
      return;
    } else if(a <= l && r <= b) {
      lazy[k].insert(x);
    } else {
      add(a, b, x, 2 * k + 1, l, (l + r) >> 1);
      add(a, b, x, 2 * k + 2, (l + r) >> 1, r);
      seg[k].insert(x);
    }
  }

  bool query(int a, int b, int low, int high)
  {
    return (query(a, b, low, high, 0, 0, sz));
  }

  void add(int a, int b, int x)
  {
    add(a, b, x, 0, 0, sz);
  }
};

int main()
{
  int N, px[100000], py[100000], qx[100000], qy[100000];
  vector< int > x, y;

  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d %d %d %d", px + i, py + i, qx + i, qy + i);
    if(px[i] > qx[i]) swap(px[i], qx[i]);
    if(py[i] > qy[i]) swap(py[i], qy[i]);
    x.push_back(px[i]);
    x.push_back(qx[i]);
    y.push_back(py[i]);
    y.push_back(qy[i]);
  }

  sort(begin(x), end(x));
  x.erase(unique(begin(x), end(x)), end(x));
  sort(begin(y), end(y));
  y.erase(unique(begin(y), end(y)), end(y));

  SegmentTree xx(x.size()), yy(y.size());
  for(int i = 0; i < N; i++) {
    px[i] = lower_bound(begin(x), end(x), px[i]) - begin(x);
    py[i] = lower_bound(begin(y), end(y), py[i]) - begin(y);
    qx[i] = lower_bound(begin(x), end(x), qx[i]) - begin(x);
    qy[i] = lower_bound(begin(y), end(y), qy[i]) - begin(y);

    if(xx.query(px[i], qx[i] + 1, py[i], qy[i] + 1) &&
       yy.query(py[i], qy[i] + 1, px[i], qx[i] + 1)) {
      puts("1");
      if(px[i] == qx[i]) yy.add(py[i], qy[i] + 1, px[i]);
      else xx.add(px[i], qx[i] + 1, py[i]);
    } else {
      puts("0");
    }
  }

}